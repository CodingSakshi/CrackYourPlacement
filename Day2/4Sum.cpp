// Problem Link: https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i ++) {
            
            for(int j = i+1; j < n; j++) {

                int left = j+1;
                int right = n-1;

                while(left < right) {
                     long long sum = nums[i];
                     sum += nums[j] ;
                     sum += nums[left]; 
                     sum += nums[right];
                    if(sum == target) {
                        s.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum > target) right--;
                    else if(sum < target) left++;
                }
            }
        }

        vector<vector<int>> ans;

        for(auto a : s) {
            ans.push_back(a);
        }

        return ans;
    }
};

