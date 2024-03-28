// // 

// You are given an integer array nums and an integer k.

// The frequency of an element x is the number of times it occurs in an array.

// An array is called good if the frequency of each element in this array is less than or equal to k.

// Return the length of the longest good subarray of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/?envType=daily-question&envId=2024-03-28

// [1,2,3,1,2,3,1,2] k=2
// [1,2,1,2,1,2,1,2] k=1
// [5,5,5,5,5,5,5]  k=4
// [1,2,3,1,2,3,3,2,1] k=2
// [1,2,3,1,2,3,3,4,1]  k=2
// [1,2,3,1,2,3,3,4,5] k=2
// [1,2,3,1,2,3,3,4,5,6]  k=2
// [1,2,3,1,2,3,3,3,1,4,5,6,7,8,9]  k=2

    int maxSubarrayLength(vector<int>& nums, int k) {
        //TC->O(2N)  SC->O(N)
        int n=nums.size();
        unordered_map<int,int> mp;
        int longest=0;
        for(int left=0,right=0;right<n;right++){
            mp[nums[right]]++;
            // cout<<mp[right]<<" ";
            if(mp[nums[right]]>k){
                while(mp[nums[right]]>k){
                    mp[nums[left++]]--;
                }
            }   
            longest=max(longest,right-left+1);
             
        }
        return longest;
    }


    int maxSubarrayLength(vector<int>& nums, int k) {

        // TC->O(1) SC->O(N)

        //INTUITION
        // EXPAND THE WINDOW UNTIL THE BAD ELEMENT ENTERS THE WINDOW AND THEN STOP EXPANDING

        // if count of characters with freq>k , then there is breach in goodness condtion

        //Unlike the above approach, the window never shrinks and remain same if there is a bad element(freq>k)

        //the current subarray maybe good or bad,
        //but the current size of subarray represent the longest good subarray enecounterred till the current situation

        //bad_elements represent the number of DISTINCT elements with freq >k in current subarray

        //STEPS
        // if count of nums[right]==k+1, increase the bad_elements

        //if bad_elements>0, then decrement the count of nums[left] 
        //and if count of nums[left] becomes k(ie it was k+1 before decrementing),decrease bad_elements

        //if the bad elements in subarray becomes zero,then it can start expanding again
        // until bad condtion is encounterred again

        int n=nums.size();
        unordered_map<int,int> mp;
        int bad_elements=0;
        int left=0,right=0;
        for(;right<n;right++){
            mp[nums[right]]++;
            if(mp[nums[right]]==k+1){ //not mp[nums[right]]>k as it would count the same bad elements again
                                    //[1,2,3,1,2,3,3,3,1,4,5,6,7,8,9] k=2
                bad_elements++;
                // cout<<bad_elements<<" ";
            }
            if(bad_elements>0){
                mp[nums[left]]--;
                if(mp[nums[left]]==k){  
                    bad_elements--;//after this, if bad_elements equals zero , 
                                    //then it is in good conditon now
                                    //and now(if bad_elements==0 then) it can continue increasing the window size 
                                    //until bad condtion is again met  
                }
                left++;
            }
        }
        return right-left;  // OR return n-left
    }

};