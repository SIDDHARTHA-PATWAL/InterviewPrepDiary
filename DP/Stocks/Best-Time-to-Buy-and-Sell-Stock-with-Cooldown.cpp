// // Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

class Solution {
public:
    int helper(int i , int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy==1){
            profit= max( -prices[i] + helper(i+1,0,prices,dp), 0 + helper(i+1,1,prices,dp));
        }
        else if(buy==0){
            profit = max( prices[i] + helper(i+1,2, prices,dp), 0 +helper(i+1,0,prices,dp));
        }
        else profit = 0+ helper(i+1,1,prices,dp);
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        //TC->O(N*3)  SC->O(N*3+N) 
        //MEMOIZATION
        vector<vector<int>> dp(prices.size(),vector<int>(3,-1));
        return helper(0,1,prices,dp);
    }
  
};