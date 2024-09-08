// Problem Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> m;

        for(int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if(m.find(diff) != m.end()) {
                return {m[diff], i};
            }
            m[nums[i]] = i;
        }
        return {0, 0};
    }
};