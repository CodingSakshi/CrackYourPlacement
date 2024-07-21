// Problem Link: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0, n = nums.size(), sum = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> a;

        for(int i = 0; i < n; i++) {
            int left = i+1;
            int right = n-1;
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if(sum == target) {
                    a.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(sum > target) {
                    right--;
                }
                else left++;
            }
        }
        vector<vector<int>> ans;
        for(auto i : a) {
            ans.push_back(i);
        }
        return ans;
    }
};