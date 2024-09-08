// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// Optimized Approach (Single Pass)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = INT_MIN;
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            minPrice = (prices[i] < minPrice) ? prices[i] : minPrice;
            profit = prices[i] - minPrice;
            maxProfit =  max(maxProfit,profit);
        }
        return maxProfit;
    }
};


// Using recursion (will give TLE)
class Solution {
public:
    int solve(int index, int buy, vector<int> &prices) {
        if(index >= prices.size()) return 0;

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index+1, 0, prices), 0 + solve(index+1, 1, prices));
        }
        else {
            profit = max(prices[index] + solve(index+1, 1, prices), 0 + solve(index+1, 0, prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices);
    }
};

// DP Top down approach 
class Solution {
public:
    int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index+1, 0, prices, dp), 0 + solve(index+1, 1, prices, dp));
        }
        else {
            profit = max(prices[index] + solve(index+1, 1, prices, dp), 0 + solve(index+1, 0, prices, dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));

        return solve(0, 1, prices, dp);
    }
};

// DP Bottom up
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
                }
                else {
                    profit = max(prices[index] + dp[index+1][1], 0 + dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
};


