# ## Count Subarrays with K Different integers

# Given an integer array nums and an integer k, return the number of good subarrays of nums.

# A good array is an array where the number of different integers in that array is exactly k.

# For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
# A subarray is a contiguous part of an array.

# https://leetcode.com/problems/subarrays-with-k-different-integers/description/

class Solution:
    def atmostK(self, nums: List[int],k:int) -> int:
        n=len(nums)
        count=0
        left=0
        dict={}
        for right in range(n):
            dict[nums[right]]=dict.get(nums[right],0)+1
            while(len(dict)==k+1):
                dict[nums[left]]-=1
                if(dict[nums[left]]==0): del dict[nums[left]]
                left+=1
            count+=right-left+1   # counting subarrays starting from left to right and 
                                # and ending at right in the current window
        return count
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        # TC->O(2N+2N)  SC->O(N)
        return self.atmostK(nums,k)-self.atmostK(nums,k-1) # count of subarrays with 
                                                        #  distinct k characters
        


        