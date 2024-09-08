// Problem link: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/


// Using sorting- TC: O(nlogn), SC: O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) v.push_back(nums[i]);
        }
        return v;
    }
};

// Single Pass- TC: O(n), SC: O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i : nums) {
            // We use abs(i) - 1 because the numbers are between 1 and n
            int index = abs(i) - 1;

            // Check if the value at this index has been marked negative
            if(nums[index] < 0) {
                // If it is negative, it means this index has been visited before,
                // so the current number is a duplicate
                ans.push_back(abs(i)); 
            } else {
                // Otherwise, mark the value at this index as negative to indicate that
                // we have visited this index
                nums[index] *= -1;
            }
        }

        
        return ans;
    }
};

