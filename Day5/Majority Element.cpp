// Problem Link: https://leetcode.com/problems/majority-element/description/

// Solution1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = 0;
        int count = 0;

        for(int i = 0; i < nums.size();i++) {

            if(count == 0) {
                me = nums[i];
                count = 1;
            }
            else if(me == nums[i]) count++;
            else count--;
        }
        
        count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(me == nums[i]) count++;
        }

        return (count > nums.size()/2) ? me : -1;
    }
};


// Solution2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};