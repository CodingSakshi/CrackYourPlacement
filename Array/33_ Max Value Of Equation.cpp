// Problem Link: https://leetcode.com/problems/max-value-of-equation/

// Iterative approach  (TLE)
// TC: O(N^2)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int r = points.size();
        int c = points[0].size();
        int maxi = INT_MIN;

        for(int i=0; i < r; i++) {
            for(int j=i+1; j < r; j++) {

                int x = abs(points[i][0]-points[j][0]);
                if(x > k) break;

                int ans = points[i][1] + points[j][1] + x;
                maxi = max(ans, maxi);
            }
        }
        return maxi;
    }
};


// Using priority queue

/* 
Explanation
Because xi < xj,
yi + yj + |xi - xj| = (yi - xi) + (yj + xj)

So for each pair of (xj, yj),
we have xj + yj, and we only need to find out the maximum yi - xi.
To find out the maximum element in a sliding window,
we can use priority queue or stack.
*/



class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>&pts, int k) {
        priority_queue<vector<int>> pq;
        pq.push({pts[0][1]-pts[0][0], pts[0][0]});
        int maxi = INT_MIN;

        for(int j = 1; j < pts.size(); j++) {
            int sum = pts[j][0] + pts[j][1];
            while(pq.size() && abs(pq.top()[1]-pts[j][0]) > k) pq.pop();   // popping from queue it not met the condition
            if(pq.size()) {     // cal the equation
                maxi = max(maxi, pq.top()[0]+sum);
            }
            pq.push({pts[j][1]-pts[j][0], pts[j][0]});
        }
        return maxi;
    }
};