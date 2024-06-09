// //   Continuous Subarray Sum

// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

// A good subarray is a subarray where:

// its length is at least two, and
// the sum of the elements of the subarray is a multiple of k.
// Note that:

// A subarray is a contiguous part of the array.
// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

// [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/description/)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<=1) return false;

        unordered_map<int,int> mp;
        int prefixSum=0;
        int n= nums.size();
        mp[0]=-1;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            // cout<<prefixSum<<endl;
            int prefixMod = (prefixSum)%k;
            // if(nums[i]>0 && prefixMod==0){
            //     // cout<<"hello";
            //      return true;}
            if(mp.find(prefixMod)!=mp.end()){
                if(i-mp[prefixMod]>1) return true;
                else continue;
            }
            else mp[prefixMod]=i;
        }
        return false;
    }
};

