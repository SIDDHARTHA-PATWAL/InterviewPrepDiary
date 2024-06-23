// // Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // TC->O(n)  SC->O(1)
        // If you are selling on ith day , then you will buy on the minimum price from zeroth day to (i-1)th day  // ith day is index too , zero baseed indexing
        int mini=prices[0]; // mini is minimum price before the ith day, ie in the left side of the array
        int profit=0;
        for(int i=0;i<prices.size();i++){
            int cost=prices[i]-mini; //current profit by selling on ith day and buying before selling on one of previous days which has the minimum price
            profit=max(profit,cost);  ///taking maximum profit of all the costs
            mini=min(mini,prices[i]);// updating mini so that minimum is changged accordingly for every selling price as we need minmmum price to buy on a day for selling the stock on a ith day
            //finding mini could have been done using Iterating the array till i-1 for every ith iteration and could result in algo getting TC O(N^2) but as we can use  the previous knowledge of mini for future iterations  the whole algo takes O(N) TC
        }
        return profit;
    }
};