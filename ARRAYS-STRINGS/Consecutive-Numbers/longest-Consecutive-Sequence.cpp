// // Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    bool lin_search( vector<int> & nums, int item , int index){
        for(int i=0; i<nums.size() ;i++){
            if(nums[i]==item){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        // // brute force 
        // //will give tle , 

        // int n= nums.size();
        // int maxi=0;

        // for(int i=0;i<n;i++){
        //     int  x = nums[i];
        //     int count=1;
        //     while(lin_search(nums,x+1,i)==true){
        //         count++;
        //         cout<<x<<" ";
        //         x=x+1;
        //     }
        //     maxi=max(maxi, count);
        // }
        // return maxi;
         
        // TC->O(2N) SC->O(N)
        unordered_set <int> st;
        for(auto it : nums){
            st.insert(it);
        }
        int n= nums.size();
        int maxi=0;

        for(int i=0;i<n;i++){
            int  x = nums[i];
            if(st.find(x-1)!=st.end()) continue;
            int count=1;
            while(st.find(x+1)!=st.end()){
                count++;
               // cout<<x<<" ";
                x=x+1;
            }
            maxi=max(maxi, count);
        }
        return maxi;
        
    }
};