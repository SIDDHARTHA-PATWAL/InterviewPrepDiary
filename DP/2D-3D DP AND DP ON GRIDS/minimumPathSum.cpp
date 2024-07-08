//  // MINIMUM PATH SUM

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        //TABULATION
        //TC->O(M*N) SC->O(M*N)
        int m =grid.size(), n =grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // dp[0][0]=grid[0][0];
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i!=0 || j!=0) {
        //             dp[i][j]=grid[i][j]+min((j-1>=0?dp[i][j-1]:INT_MAX),(i-1>=0?dp[i-1][j]:INT_MAX));
        //             // cout<<dp[i][j]<<" ";
        //         }  
        //     }
        // }
        // return dp[m-1][n-1];

        //SPACE OPTIMZATION
        //TC->O(M*N) SC->O(N)
        // you can also take min(m,n) and 
        // if m is min then you can iterate the grid vertically instead of horizontally in case of n
        vector<int> dp(n);
        dp[0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i!=0 || j!=0) {
                    dp[j]=grid[i][j]+min((j-1>=0?dp[j-1]:INT_MAX),(i-1>=0?dp[j]:INT_MAX));
                    // cout<<dp[j]<<" "<<i<<" "<<j<<endl;
                }  
            }
        }
        return dp[n-1];
    }
};