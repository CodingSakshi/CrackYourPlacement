// Problem Link: https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;

        for(int i : nums1) {
            for(int j : nums2) {
                m[i+j]++;
            }
        }

        int count=0;

        for(int i : nums3) {
            for(int j : nums4) {
                int target = -(i+j);
                if(m.find(target) != m.end()) {
                    count += m[target];
                }
            }
        }

        return count;
    }
};