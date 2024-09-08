// Problem Link: https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int me1 = INT_MAX;
        int me2 = INT_MAX;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(count1 == 0 && nums[i] != me2) {
                me1 = nums[i];
                count1++;
            }
            else if(count2 == 0 && nums[i] != me1) {
                me2 = nums[i];
                count2++;
            }
            else if(me1 == nums[i]) {
                count1++;
            }
            else if(me2 == nums[i]){
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(int i = 0; i < n; i++) {
            if(me1 == nums[i]) count1++;
            if(me2 == nums[i]) count2++;
        }

        vector<int> ans;

        if(count1 > floor(n/3)) ans.push_back(me1);
        if(count2 > floor(n/3)) ans.push_back(me2);

        return ans; 
        
    }
};