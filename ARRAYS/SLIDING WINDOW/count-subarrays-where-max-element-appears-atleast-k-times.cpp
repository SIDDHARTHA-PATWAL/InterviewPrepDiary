// // // Count Subarrays Where Max Element Appears Atleast k Times

// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            //TC->O(2N) SC->O(1) 
            // //  SLIDIING WINDOW 
            //THE APPRAOCH CAN BE FORMULATED BY CONSIDERING THE O(N^2) TC APPROACH 
            //AND SEE HOW EFFICIENTLY WE CAN CUT OFF THE INTEMEDIATORY STEPS,
            //LIKE NOT INITIALIZING RIGHT TO EQUAL TO LEFT EVERYTIME LEFT INCREMENTS

            int n=nums.size();
            int maxi=*max_element(nums.begin(),nums.end());
            int maxi_freq=0;
            long long count=0;

            for(int left=0,right=0;right<n;right++){
                if(nums[right]==maxi) maxi_freq++;
                while(maxi_freq==k){
                    count+= n-right; //windows starting from current left to indices till end 0f array

                    if(nums[left]==maxi){
                        maxi_freq--;
                    }
                    left++;
                }
            }
            return count;
        }
};