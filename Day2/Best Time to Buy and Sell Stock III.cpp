// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/


// Using recursion (will give TLE)
class Solution {
public:
    int solve(int index, int buy, int limit, vector<int> &prices) {
        if(index >= prices.size() || limit == 0) return 0;

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index+1, 0, limit, prices), 0 + solve(index+1, 1, limit, prices));
        }
        else {
            profit = max(prices[index] + solve(index+1, 1, limit-1, prices), 0 + solve(index+1, 0, limit, prices));
        }
        return profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return solve(0, 1, 2, prices);
    }
};


// DP top down approach (will give TLE)
class Solution {
public:
    int solve(int index, int buy, int limit, vector<int> &prices, vector<vector<vector<int>>> dp) {
        if(index >= prices.size() || limit < 0) return 0;
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index+1, 0, limit, prices, dp), 0 + solve(index+1, 1, limit, prices, dp));
        }
        else {
            profit = max(prices[index] + solve(index+1, 1, limit-1, prices, dp), 0 + solve(index+1, 0, limit, prices, dp));
        }
        return dp[index][buy][limit] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (2, -1)));

        return solve(0, 1, 1, prices, dp);
    }
};


// Dp Bottom up approach 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+2, vector<vector<int>>(2, vector<int> (2, 0)));

        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int limit = 0; limit <= 1; limit++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[index] + dp[index+1][0][limit], 0 + dp[index+1][1][limit]);
                    }
                    else {
                        profit = max(prices[index] + (limit > 0 ? dp[index + 1][1][limit - 1] : 0), 0 +  dp[index+1][0][limit]);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        // return solve(0, 1, 1, prices, dp);
        return dp[0][1][1];
    }
};


// space optimized
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int> (2, 0));
        vector<vector<int>> curr(2, vector<int> (2, 0));

        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int limit = 0; limit <= 1; limit++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[index] + next[0][limit], 0 + next[1][limit]);
                    }
                    else {
                        profit = max(prices[index] + (limit > 0 ? next[1][limit - 1] : 0), 0 +  next[0][limit]);
                    }
                    curr[buy][limit] = profit;
                }
                next = curr;
            }
        }
        return next[1][1];
    }
};