// Problem Link: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVol = 0; 

        for(int i = 0, j = height.size()-1; i < j;) {
            int minHeight = min(height[i], height[j]);
            int width = j-i;
            int vol = minHeight*width;

            maxVol = max(maxVol, vol);

            if(height[i] < height[j]) i++;
            else j--;
        }

        return maxVol;
    }
};
