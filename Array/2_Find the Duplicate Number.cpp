// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0, fast = 0;

        // Finding the intersection point in the cycle using Floyd's Tortoise and Hare method
        while (true) {
            slow = nums[slow];         // Move slow pointer one step
            fast = nums[nums[fast]];   // Move fast pointer two steps
            if (slow == fast) break;   // Cycle detected when slow and fast pointers meet
        }

        // Initializing a new pointer to find the start of the cycle (duplicate number)
        int slow2 = 0;
        while (slow != slow2) {
            slow = nums[slow];     // Move both pointers one step at a time
            slow2 = nums[slow2];   // until they meet at the start of the cycle (duplicate number)
        }

        return slow2; // The duplicate number
    }
};
