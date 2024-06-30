// // Largest Rectangle in Histogram

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // TC->O(2*N + 2*N + N ) SC->O(4N)
        int  n = heights.size();int maxi=0;
        vector<int> nse(n,n); stack<int> sn;
        vector<int> pse(n,-1); stack<int> sp;

        for(int i=n-1;i>=0;i--){
            // if(sn.empty()) sn.push(i);
            // else{
                while(!sn.empty() && heights[i]<=heights[sn.top()]){
                    sn.pop();
                }
                if(!sn.empty()) nse[i]= sn.top();
                sn.push(i);
            // }
        }
        for(int i=0;i<n;i++){
            while(!sp.empty() && heights[i]<=heights[sp.top()]){
                    sp.pop();
            }
            if(!sp.empty()) pse[i]= sp.top();
            sp.push(i);   
        }
       

        for(int i=0;i<n;i++){
            int area= ((nse[i]-1)-(pse[i]+1)+1)*heights[i];
            maxi= max(area, maxi);
        }
        return maxi;
    }
};