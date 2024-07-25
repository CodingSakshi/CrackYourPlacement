// Problem Link: https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxReach = max(maxReach, i+nums[i]);  
            if(maxReach <= i) return false;      
            if(maxReach >= nums.size()-1) return true;  
        }
        return false;
    }
};


