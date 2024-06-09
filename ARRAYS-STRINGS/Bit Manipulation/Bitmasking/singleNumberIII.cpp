// // Single Number III

// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]
 

// Constraints:

// 2 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each integer in nums will appear twice, only two integers will appear once.

// https://leetcode.com/problems/single-number-iii/

// https://leetcode.com/problems/single-number-iii/solutions/5233206/demon-level-explanation-3-approaches/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //BITMASKING
        //TC->O(2N) SC->O(1)
        vector <int> ans(2,0);
        int xor_full = 0;
        for(auto it:nums){
            xor_full^=it;
        }
        int rightMost_one_bit = xor_full & -(unsigned(xor_full));
        // cout<<rightMost_one_bit<<endl;
        for(auto it:nums){
            if((it & rightMost_one_bit) ==0) ans[0]^=it;
            else ans[1]^=it;
        }
        return ans;
    }
};