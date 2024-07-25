// Problem Link: https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int maxReach = 0;
        int jump = 0;

        for(int i = 0; i < nums.size()-1; i++) {  // The goal is to reach or go beyond the last element, and since the last element itself doesn't contribute to further jumps, we can stop at nums.size() - 1.
            maxReach = max(maxReach, i+nums[i]);
            if(i==farthest) {
                cout << i << " " << nums[i] << " " << farthest << " " << maxReach << endl;
                farthest = maxReach;
                jump++;
            }
        }
        return jump;
    }
};