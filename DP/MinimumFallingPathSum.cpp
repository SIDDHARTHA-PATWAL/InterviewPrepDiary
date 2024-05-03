// // MINIMUM FALLING PATH SUM

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row 
// that is either directly below or diagonally left/right. 
// Specifically, the next element from position (row, col) will be 
// (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //TABULATION
        //TC->O(N^2)+O(2N)  SC->O(N^2)
        // int  n =matrix.size();

        // vector<vector<int>> dp(n,vector<int>(n,-1));

        // for(int j=0;j<n;j++){
        //     dp[0][j]=matrix[0][j];
        // }
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         dp[i][j]= matrix[i][j]+ min(min(j-1>=0?dp[i-1][j-1]:INT_MAX,dp[i-1][j]),j+1<n?dp[i-1][j+1]:INT_MAX);
        //     }
        // }
        // int mini=INT_MAX;
        // for(int j=0;j<n;j++){
        //     mini=min(mini,dp[n-1][j]);
        // }
        // return mini;

        // SPACE OPTIMZATION
        // TC->O(N^2)+O(2N) SC->O(N)
        int  n =matrix.size();
        
        vector<int> dp(n,-1);

        for(int j=0;j<n;j++){
            dp[j]=matrix[0][j];
        }
        int for_next=dp[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
               
                int val= matrix[i][j]+ min(min(j-1>=0?for_next:INT_MAX,dp[j]),j+1<n?dp[j+1]:INT_MAX);
                for_next=dp[j];
                dp[j]=val;
                // cout<<dp[j]<<" ";
            }
            for_next=dp[0];
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[j]);
        }
        return mini;
    }
};