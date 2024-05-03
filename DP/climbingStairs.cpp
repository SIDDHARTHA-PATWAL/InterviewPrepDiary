// // CLIMBING STARIS

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// https://leetcode.com/problems/climbing-stairs/description/


class Solution {
public:

    //MEMOIZATION
    // TC->O(N) SC->O(N) + O(N)
    // int climbStairsutil(int n,vector<int> & dp) {
    //     if(n==0) return 1;
    //     if(n<0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=climbStairsutil(n-1,dp)+climbStairsutil(n-2,dp);
    // }
    // int climbStairs(int n){
    //     vector <int> dp(n+1,-1);
    //     return climbStairsutil(n,dp);
    // }

    //SPACE OPTIMIZATION
    // TC->O(N) SC->O(1)
    int climbStairs(int n){
        int a=1,b=1;
        if(n==0) return a;
        if(n==1) return b;
        if(n<0) return 0;
        int res=0;
        for(int i=2;i<=n;i++){
            res=a+b;
            b=a;
            a=res;
        }
        return res;
    }
};