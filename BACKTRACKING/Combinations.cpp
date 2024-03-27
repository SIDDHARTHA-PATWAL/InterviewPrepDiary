//COMBINATIONS

// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

// https://leetcode.com/problems/combinations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combinations(vector<vector<int>> &ans ,vector<int>& temp,int n , int k ){   
        if(temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        if(n==0) return; 
        combinations(ans, temp , n-1,k);  //don't pick n
        temp.push_back(n);
        combinations(ans, temp,n-1,k);  //pick n
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        //pick unpick
        //at worst case TC->O(2^n)  SC->O(k*)XO(n/2) if n is even  or O(k)XO((n-1)/2 or (n+1)/2) if n is odd through nCr formula
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(ans , temp,n , k );
        return ans;
    }
};

// COMBINATION SUM

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void solve(vector<vector<int>> & ans,vector<int>& temp,vector<int>& candidates, int target ,int i,int sum){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target) return;
        for(;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(ans, temp,candidates,target,i,sum+candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //choosing one out of the all the options and in a way to remove duplicates combinations or set you can say
        //TC-> it depends on the target , has to be of exponential order
        vector<vector<int>> ans;
        vector<int> temp;
        solve (ans, temp, candidates , target ,0,0);
        return ans;
    }
};

