// Problem Link: https://leetcode.com/problems/next-permutation/

/*
1. Find the rightmost element smaller than the next one (let, arr[i])
2. Find the rightmost element greated than the arr[i] (let, arr[j])
3. Swap arr[i] and arr[j]
4. Reverse seq. of elements to the right of index i.
 */


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {    // handling edge case: when the given permutation is already the largest possible permutation
            int j = n - 1;
            // 2. Find the element just larger than nums[i]
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            // 3. Swap
            swap(nums[i], nums[j]);
        }

        // 4. Sort the remaining elements after i that is from i+1
        reverse(nums.begin() + i + 1, nums.end());
    }
};


