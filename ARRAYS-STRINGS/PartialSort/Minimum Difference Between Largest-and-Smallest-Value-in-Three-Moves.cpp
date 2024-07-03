// // Minimum Difference Between Largest and Smallest Value in Three Moves

You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.
Example 3:

Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109


class Solution {
public:
    int minDifference(vector<int>& nums) {
        // Changing an element of nums arrays within the range the of nums array i.e [min,max]
        // would be equivalent to deleting that element form the array and it will not be in the  
        //calculation of difference of min and max of that array at that time.

        //It's important to understand that deleting elements that are not the largest or smallest 
        //won't reduce the overall difference and is a waste of moves.
        // Let's sort our array to evaluate the values more effectively.

        //We should focus on removing elements at the ends of the sorted array since the largest and smallest values are there.
        // By removing these elements, we can reduce the range and minimize the difference effectively.



        // Once we sort the array, how do we know which three values to target? 
        // There are four possible optimal scenarios:

        //     Removing the three largest elements.
        //     Removing the two largest and one smallest elements.
        //     Removing one largest and two smallest elements.
        //     Removing the three smallest elements.

        //TC->O( NLOGN + 4 )   SC->O(LOGN)
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(int left=0,right= n-4;left<=3;left++,right++){
            mini= min(mini, nums[right]-nums[left]);
        }
        return mini;
    }

    int minDifference(vector<int>& nums) {
        //TC->O(n.log4  + n + 4log4 + 4 )  SC->O(1)
        int n = nums.size();
        if(n<=4) return 0;
        int mini= INT_MAX;

        // PARTIAL_SORT rearranges the elements in the range [first, last), 
        //in such a way that the elements before middle are sorted in ascending order, 
        // whereas the elements after middle are left without any specific order
        partial_sort(nums.begin(),nums.begin()+4, nums.end());

        //nth_element rearranges the elements such that the element at the n-th position
        // is the one that would be in that position in a fully sorted array, 
        //and all elements before it are less than or equal to it, 
        //and all elements after it are greater than or equal to it.
        nth_element(nums.begin()+4,nums.begin()+n-4,nums.end());
        
        sort(nums.begin()+n-4,nums.end());
        for(int left=0,right= n-4;left<=3;left++,right++){
            mini= min(mini, nums[right]-nums[left]);
        }
        return mini;
    }
};