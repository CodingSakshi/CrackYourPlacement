// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

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