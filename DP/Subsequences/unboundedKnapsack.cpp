// UNBOUND KNAPSACK
// Knapsack with Duplicate Items

// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

// This innvolves computing value in dp table from the previous row and some prev item at the current row

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i, int w , int val[],int wt[], vector<vector<int>>& dp){
        if(i==0){
            return w/wt[0]*val[0];
        }
        if(dp[i][w]!=-1)return dp[i][w];
        int notTake = 0 + helper(i-1,w , val, wt, dp);
        int take= INT_MIN;
        if(wt[i]<=w) take= val[i] + helper(i, w-wt[i], val , wt, dp);
        return dp[i][w]=max(notTake, take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        //TC->O(N*W+N) SC->O(N*W)
        //MEMOIZATION 
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return helper(N-1, W, val , wt, dp);
    }
   
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        // TC->O(N*W)  SC->O(W)
        // SPACE OPTIMZATION ONE ROW 
        vector<int> dp(W+1,0);
        for(int w=0;w<=W;w++){
            dp[w]= w/wt[0]*val[0];
        }
        for(int i=1;i<N;i++){
            for(int w=0;w<=W;w++){
                int notTake = 0+ dp[w];
                int take=INT_MIN;
                if(wt[i]<=w)take = val[i]+ dp[w-wt[i]];
                dp[w]= max(notTake,take);
            }
        }
        return dp[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends