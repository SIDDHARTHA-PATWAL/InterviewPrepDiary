// // Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        //TC->O(~N^2) SC->O(1)
        int n =nums.size();
        int max_len=0;
        for(int i=0;i<n;i++){
            int mini=nums[i],maxi=nums[i];
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                if(maxi-mini<=limit){
                    max_len=max(max_len,j-i+1);
                }
                else break;
            }
        }
        return max_len;
        
        //TC->O(NLOGN) TC->O(N)
        // MULTISET-
        // Using a multiset, we can efficiently track elements within the current window. 
        // Inserting and removing elements take logarithmic time, 
        // while finding the maximum and minimum values is constant time, 
        // as they are at the ends of the sorted container.
        // A multiset, unlike a set, allows multiple instances of the same element 
        // and can be thought of as a combination of a min heap and a max heap.
        int n=nums.size();
        multiset<int> window;
        int left=0,right=0, max_len=0;
        while(right<n){
            window.insert(nums[right++]);
            while(*window.rbegin()-*window.begin()>limit){
                window.erase(window.find(nums[left++]));
            }
            max_len= max(max_len,right-left);
        }
        return max_len;

        //NON-SHRINKING SLIDING WINDOW
        //for this,chnage the while loop to if condition
        //IF BAD CONDTIION OCCURRS, THEN the window doesn't shrink but shrinks instead
        int n=nums.size();
        multiset<int> window;
        int left=0,right=0, max_len=0;
        while(right<n){
            window.insert(nums[right++]);
            if(*window.rbegin()-*window.begin()>limit){
                window.erase(window.find(nums[left++]));
            }
        }
        return right-left;

        //conceptually right , as "right" is incremented at the end of the while loop for "roght"
        int n=nums.size();
        multiset<int> window;
        int left=0,right=0, max_len=0;
        while(right<n){
            window.insert(nums[right]);
            if(*window.rbegin()-*window.begin()>limit){
                window.erase(window.find(nums[left++]));
            }
            right++;  
        }
        return right-left;
    }
};