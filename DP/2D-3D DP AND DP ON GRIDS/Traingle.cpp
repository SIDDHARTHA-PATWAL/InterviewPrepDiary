// // Triangle 

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

https://leetcode.com/problems/triangle/

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //TABULATION
        //TC->O(M^2) SC->O(M^2)
        // int m =triangle.size();
        // vector<vector<int>> dp(m, vector<int>(m,-1));
        // for(int j=0;j<m;j++){
        //     dp[m-1][j]=triangle[m-1][j];
        // }
        
        // for(int i=m-2;i>=0;i--){
        //     for(int j=0;j<=i;j++){
            
        //             dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        //             // cout<<dp[i][j]<<" ";
        //     }
        // }
        // return dp[0][0];

        //SPACE OPTIMZATION
        //TC->O(M*N) SC->O(M)
        int m =triangle.size();
        vector<int> dp(m,-1);
        for(int j=0;j<m;j++){
            dp[j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
            
                    dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
                    // cout<<dp[i][j]<<" ";
            }
        }
        return dp[0];
    }
};