# # # Kth Largest Element in an Array

# Given an integer array nums and an integer k, return the kth largest element in the array.

# Note that it is the kth largest element in the sorted order, not the kth distinct element.

# Can you solve it without sorting?

# https://leetcode.com/problems/kth-largest-element-in-an-array/

# Example 1:

# Input: nums = [3,2,1,5,6,4], k = 2
# Output: 5
# Example 2:

# Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
# Output: 4
 

# Constraints:

# 1 <= k <= nums.length <= 105
# -104 <= nums[i] <= 104

import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        pq=[]
        i=0
        while(len(pq)<k):
            heapq.heappush(pq,nums[i])
            i+=1
        
        for x in range(i,len(nums)):
            if pq[0]<nums[x]:
                heapq.heappop(pq)
                heapq.heappush(pq,nums[x])
        return pq[0]
    
# in c++ -- anotehr solution
# class Solution {
# public:
#     int findKthLargest(vector<int>& nums, int k) {
#         //well this approach may be opitmuzed , just for doing\U0001f643

#         //tc->O(NlogN)+O(KlogN)   SC->O(N)
#         //O(NlognN) ROUGHLY
#         priority_queue<int> pq;
#         for(auto it :nums){
#             pq.push(it);
#         }
#         //if the kth largest consider uniqueness also , 
#         // int count=0;
#         // int prev =INT_MAX;;
#         // while(count<k){
#         //     if(prev!=pq.top()){
#         //         count++;  //for counting count th largest value  , unique ofcourse
#         //     }
#         //     prev=pq.top();

#         //     pq.pop();
#         // }
#         // return prev;
#         int count=0;
#         int it= pq.top();
#         //o(KlogN) roughly
#         while(count<k){
#             count++;
#             it= pq.top();
#             pq.pop();
#         }
#         return it;
#     }
# };