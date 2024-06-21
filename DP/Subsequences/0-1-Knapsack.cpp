// 0 - 1 Knapsack Problem

//You are given weights and values of N items, 

//put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note that we have only one quantity of each item.
//In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
//which represent values and weights associated with N items respectively. 
//Also given an integer W which represents knapsack capacity, 
//find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
// You cannot break an item, either pick the complete item or dont pick it (0-1 property).

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // int helper(int i , int w ,int wt[], int val[], vector<vector<int>>&dp ){
    //     //MEMOIZATION TC->O(N*W) SC->O(N*W+N)
    //     if(i==0){
    //         if(wt[0]<=w){
    //             return val[0];
    //         }
    //         else return 0;
    //     }
    //     if(dp[i][w]!=-1){
    //         return dp[i][w];
    //     }
    //     int notTake=0;
    //     notTake= 0 + helper(i-1,w, wt,val,dp);
    //     int take=INT_MIN;
    //     if(wt[i]<=w){
    //         take= val[i]+ helper(i-1, w-wt[i],wt,val,dp);
    //     }
    //     return dp[i][w]=max(notTake, take);
    // }
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //   // Your code here
    // vector<vector<int>> dp(n, vector<int>(W+1, -1));
    //   return helper(n-1, W , wt, val,dp);
       
    // }


    //Function to return max value that can be put in knapsack of capacity W.
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //   //   tabulation tc-> O(N*W) SC->O(N*W)
    //   vector<vector<int>> dp(n, vector<int>(W+1, -1));
    //   for (int i=0;i<W+1;i++){
    //       if(wt[0]<=i)dp[0][i]= val[0];
    //       else dp[0][i]=0;
    //   }
    //   for(int i=1;i<n;i++){
    //       for(int w=0;w<W+1;w++){
    //           int take=INT_MIN;
    //           if(wt[i]<=w){
    //             take= val[i]+ dp[i-1][w-wt[i]];
    //          }  
    //          int notTake=0;
    //          notTake= 0 + dp[i-1][w];
    //          dp[i][w]=max(notTake, take);
    //       }
    //   }
    //   return dp[n-1][W];
       
    // }
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //   //   2-row space optimization tc-> O(N*W) SC->O(2*W)
    //   vector<int> prev(W+1,0) , curr(W+1,0);
    //   for (int i=0;i<W+1;i++){
    //       if(wt[0]<=i)prev[i]= val[0];
    //       else prev[i]=0;
    //   }
    //   for(int i=1;i<n;i++){
    //       for(int w=0;w<W+1;w++){
    //           int take=INT_MIN;
    //           if(wt[i]<=w){
    //             take= val[i]+ prev[w-wt[i]];
    //          }  
    //          int notTake=0;
    //          notTake= 0 + prev[w];
    //          curr[w]=max(notTake, take);
    //       }
    //       prev=curr;
    //   }
    //   return prev[W];
       
    // }
    
     //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      //   1-row space optimization tc-> O(N*W) SC->O(W)
      vector<int> prev(W+1,0) ;
      for (int i=0;i<W+1;i++){
          if(wt[0]<=i)prev[i]= val[0];
          else prev[i]=0;
      }
      for(int i=1;i<n;i++){
          
     // RIGHT TO LEFT TRAVERSAL NEEDED FOR ONE ARRAY SPACE OPTIMIZATION
    // LEFT TO RIGHT WILL NOT WORK FOR SINGLE ARRAY SPACE OPTIMIZATION
    // AS LEFT VALUES NEED FOR CURR POSITION WILL ALREADY HAVE BEEN OVERWRITTEN
          for(int w=W+1;w>=0;w--){
              int take=INT_MIN;
              if(wt[i]<=w){
                take= val[i]+ prev[w-wt[i]];
             }  
             int notTake=0;
             notTake= 0 + prev[w];
             prev[w]=max(notTake, take);
          }
      }
      return prev[W];
       
    }
};


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
