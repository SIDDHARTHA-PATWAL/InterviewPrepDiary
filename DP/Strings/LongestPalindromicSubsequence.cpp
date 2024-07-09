// // Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

https://leetcode.com/problems/longest-palindromic-subsequence/description/

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.


class Solution {
public:
    int f(int i , int j , string &s, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]= 2+ f(i+1,j-1,s,dp);
        else return dp[i][j]=max(f(i+1,j,s,dp),f(i,j-1,s,dp));
    }
    int longestPalindromeSubseq(string s) {
        MEMOIZATION
        TC->O(N^2)  SC->O(N^2 + N recursive stack space)
        int  n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,s,dp);
    }


    int longestPalindromeSubseq(string s) {
        // TABULATION 
        //  TC->O(N^2)  SC->O(N^2)
        int  n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //base case
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dp[i][j]=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i!=j & i<j){
                    if(s[i]==s[j]) dp[i][j]= 2+ dp[i+1][j-1];
                    else dp[i][j]= max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }

    
    int longestPalindromeSubseq(string s) {
        // SPACE OPTIMIZATION 
        //  TC->O(N^2)  SC->O(2N)
        int  n = s.length();
        vector<int> below(n,0),above(n,0);
        below[n-1]=1;
        for(int i=n-2;i>=0;i--){
            above[i]=1;
            for(int j=0;j<n;j++){ 
                if(i!=j & i<j){
                    if(s[i]==s[j]) above[j]= 2+ below[j-1];
                    else above[j]= max(below[j], above[j-1]);
                }
            }
            below=above;
        }

        return below[n-1];
    }
};