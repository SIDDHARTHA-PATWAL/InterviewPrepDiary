// // Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

https://leetcode.com/problems/longest-common-subsequence/description/

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.


class Solution {
public:

    // f(i,j)-> lcs of string1[0 ... i] and string2[0,...j]

    int f(int i,int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(j<0 || i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] =1+ f(i-1,j-1, text1, text2,dp);
        else return dp[i][j]=0 + max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {

            MEMOIZATION
            TC-> (N*M) SC->O(N*M + (N+M) recursionstack space)
        int n= text1.length(), m = text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }

    int longestCommonSubsequence(string text1, string text2) {

        // TABULATION
         // TC-> (N*M) SC->O(N*M )

         //Shifting of index by +1
        int n= text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+ dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {

        // SPACE OPTIMIZATION
         // TC-> (N*M) SC->O(M )

         //Shifting of index by +1
        int n= text1.length(), m = text2.length();
        vector<int> prev(m+1,0) , curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) curr[j]=1+ prev[j-1];
                else curr[j]= max(prev[j], curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }

};