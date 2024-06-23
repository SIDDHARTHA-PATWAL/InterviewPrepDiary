// // Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

class Solution {
public:

    int helper(int i , int buy,int count, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(i==prices.size()) return 0;
        if(count==0) return 0;
        if(dp[i][buy][count]!=-1)return dp[i][buy][count];
        int profit=0;
        if(buy){
           profit= max( -prices[i] + helper(i+1,0,count,prices,dp), 0 + helper(i+1,1,count,prices,dp));
        }
        else{
            profit = max( prices[i] + helper(i+1,1,count-1, prices,dp), 0 +helper(i+1,0,count,prices,dp));
        }
        return dp[i][buy][count]= profit;
    }
    int maxProfit(vector<int>& prices) {
        //TC->O(N*2*3)  SC->O(N*2*3+N) 
        //MEMOIZATION
        int n =prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // Start from day 0, allowed to buy, with up to 2 transactions left
        return helper(0,1,2,prices,dp);
    }

    int maxProfit(vector<int>& prices) {
        //TC->O(N*2*3)  SC->O(N*2*3) 
        //TABULATION
        int n =prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        //NO  NEED FOR INITIALIZING BASE CASES AS BASE CASES HAVE '0' VALUE AND DP HAS BEEN PREINITIALIZED WITH '0'
        // for(int i=0;i<=n;i++){
        //     for(int buy=0;buy<=1;buy++){
        //         dp[i][buy][0]=0;
        //     }
        // }
        // for(int buy=0;buy<=1;buy++){
        //     for(int count=0;count<=2;count++){
        //         dp[n][buy][count]=0;
        //     }
        // }
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                    int profit=0;
                    if(buy){
                    profit= max( -prices[i] + dp[i+1][0][count], 0 + dp[i+1][1][count]);
                    }
                    else{
                        profit = max( prices[i] + dp[i+1][1][count-1], 0 +dp[i+1][0][count]);
                    }
                    dp[i][buy][count]= profit;
                }
            }
        }

        // Start from day 0, allowed to buy, with up to 2 transactions left
        return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {
        //TC->O(N*2*3)  SC->O(2*3) 
        //SPACE OPTIMIZATION
        int n =prices.size();
        vector<vector<int>> after(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        
     
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                    int profit=0;
                    if(buy){
                    profit= max( -prices[i] + after[0][count], 0 + after[1][count]);
                    }
                    else{
                        profit = max( prices[i] + after[1][count-1], 0 +after[0][count]);
                    }
                    curr[buy][count]= profit;
                }
            }
            after=curr;
        }

        // Start from day 0, allowed to buy, with up to 2 transactions left
        return curr[1][2];
    }

};