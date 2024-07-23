// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0]++;

        int prefixSum=0;
        int count=0;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if(m.find(prefixSum-k) != m.end()) {
                count += m[prefixSum-k];
            }
            m[prefixSum]++;
        }
        return count;
    }
};