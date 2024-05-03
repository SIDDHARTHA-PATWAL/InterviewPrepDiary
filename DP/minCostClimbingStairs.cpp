// // MIN COST CLIMBING STAIRS

// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

// https://leetcode.com/problems/min-cost-climbing-stairs/description/


class Solution {
public:
    // int helper(vector<int> &cost ,int n){
    //     if(n==0) return 0;
    //     int left=helper(cost,n-1)+cost[n-1];
    //     int right=INT_MAX;
    //     if(n>1){ right=helper(cost,n-2)+cost[n-2];}
    //     if(n==1){ right=0;}
    //     return min(left,right);
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     return helper(cost,n);
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     vector<int> dp(n+1);
    //     dp[0]=0,dp[1]=0;
    //     for(int i=2;i<=n;i++){
    //         dp[i]= min((dp[i-1]+cost[i-1]),dp[i-2]+cost[i-2]);
    //     }
    //     return dp[n];
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n);
        dp[0]=cost[0],dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]= cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n);
    //     int a= cost[0];
    //     int b= cost[1];
    //     int c=0;
    //     for (int i = 2; i < n; i++) {
    //         c = cost[i] + min(b, a);
    //         a=b;
    //         b=c;
    //     }
    //     return min(b, a);
    // }
};