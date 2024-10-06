// Find First and Last Position of Element in Sorted Array
// Solved
// Medium
// Topics
// Companies
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/


// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109


class Solution {
public:
    int firstoc(vector<int> & nums,int n ,int target){
        int low=0,high=n-1,oc=-1;
        int mid=low+(high-low)/2;
        while(low<=high){
            if(nums[mid]==target){
                oc=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return oc;
    }
    int lastoc(vector<int> & nums,int n ,int target){
        int low=0,high=n-1,oc=-1;
        int mid=low+(high-low)/2;
        while(low<=high){
            if(nums[mid]==target){
                oc=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return oc;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        int n=nums.size();
        v[0]=firstoc(nums,n,target);
        v[1]=lastoc(nums,n,target);
        return v;
    }
};