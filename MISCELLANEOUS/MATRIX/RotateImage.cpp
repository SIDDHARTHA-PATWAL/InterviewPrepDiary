// /// Rotate Image

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// https://leetcode.com/problems/rotate-image/description/

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Example 2:


// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000


class Solution {
public:
    void reverse(vector<int> & row,int start,int end){
        while(start<=end){
            swap(row[start],row[end]);
            start++ ,end-- ;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        //brute force  TC->O(N^2)  SC->O(N^2)
        // int n=matrix.size();
        // vector<vector<int>> ans(n,vector<int> (n));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         ans[j][(n-1)-i]=matrix[i][j];
        //     }
        // }
        // matrix=ans;

        //optimal inplace 
        //first transpose the matrix and then reverse each and every row
        int n=matrix.size();

        //step1-transpose
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse every row  // use eeither stl reverse() fn or make your own
        for(int i=0;i<n;i++){
            reverse(matrix[i],0,n-1);
        }
    }
};