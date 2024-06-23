// // Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

class Solution {
public:
    int helper(int i , int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit= max( -prices[i] + helper(i+1,0,prices,dp), 0 + helper(i+1,1,prices,dp));
        }
        else{
            profit = max( prices[i] + helper(i+1,1, prices,dp), 0 +helper(i+1,0,prices,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        //TC->O(N*2)  SC->O(N*2+N) 
        //MEMOIZATION
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }

    int maxProfit(vector<int>& prices) {
        //TC->O(N*2)  SC->O(N*2) 
        //TABULATION
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy) dp[i][buy]= max(-prices[i]+dp[i+1][0], 0+ dp[i+1][1]);
                else dp[i][buy]=max(prices[i]+dp[i+1][1], 0+ dp[i+1][0]);
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        //TC->O(N*2)  SC->O(N) 
        //SPACE OPTIMIZATION TWO ROW
        int n=prices.size();
        vector<int> ahead(2,0),curr(2,0);
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy) curr[buy]= max(-prices[i]+ahead[0], 0+ ahead[1]);
                else curr[buy]=max(prices[i]+ahead[1], 0+ ahead[0]);
            }
            ahead=curr;
        }
        return ahead[1];
    }

};