//SUBARRAY PRODUCT ;ESS THAN K

// Given an array of integers nums and an integer k, 
//return the number of contiguous subarrays 
//where the product of all the elements in the subarray is strictly less than k.

// https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        //sliding window concept  -is applicable when the problem entails 
        //achieving a goal using subarrays, and individual elements 
        //cannot be independently selected.

        //TC->O(1)  SC->O(1)

        if(k==0 ||k==1)return 0;

        int product=1;int n=nums.size();
        int count=0;

        //each window represnts a subarray were products of 
        //its contiguous elements are less than k
        //the window exapnds by increasing right until product >=k
        // when product>=k ,then window is shrinked by incrementing left
        //and update the product accordingly
        for(int left=0,right=0;left<n,right<n;right++){
            product*= nums[right];

            while(product>=k) product/= nums[left++];
            count+= (right-left) +1; // it sees the subarrays with conditon met which are ending
                                    // at the right pointer of the window 
                                    //and not all possible subarrrays of the window
        }
        return count;
    }
};