// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[x-1] != nums[i]) {
                nums[x] = nums[i];
                x++;
            }
        }
        return x;
    }
};






