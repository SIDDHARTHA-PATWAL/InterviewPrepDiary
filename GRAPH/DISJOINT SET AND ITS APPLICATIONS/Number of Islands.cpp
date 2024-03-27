// Number Of Islands

// You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
// Note : An island means group of 1s such that they share a common side.

// https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public: 
        vector<int>parent,rank,size;
        DisjointSet(int n){
            rank.resize(n,0);
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(node==parent[node]) return node;
            return parent[node]=findParent(parent[node]);
        }
        void UnionbyRank(int u ,int v){
            int ult_u=findParent(u);
            int ult_v=findParent(v);
            if(ult_u!=ult_v){
                if(rank[ult_u]>rank[ult_v]){
                    parent[ult_v]=ult_u;
                }
                else if(rank[ult_u]<rank[ult_v]){
                    parent[ult_u]=ult_v;
                }
                else{
                     parent[ult_v]=ult_u; rank[ult_u]++;
                }
            }
        }
        void UnionbySize(int u ,int v){
            int ult_u=findParent(u);
            int ult_v=findParent(v);
            if(ult_u!=ult_v){
                if(size[ult_u]>=size[ult_v]){
                    parent[ult_v]=ult_u; size[ult_u]++;
                }
                else if(size[ult_u]<size[ult_v]){
                    parent[ult_u]=ult_v; size[ult_v]++;
                }
            }
        }
    
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        //vector<vector<int>> matrix(n,vector<int>(m,0));  // matrix to store the land(1) and water(0) values
        int k=operators.size();
        DisjointSet ds(n*m); int visited[n][m]={0};// will do the work of visited array, also the work of matrix array to store land(1) and water(0) values 
        int output=0;  //output is the  number of islands after connection , dynamically
        vector<int> ans;
        for(auto it: operators){
            int row=it[0];
            int col=it[1];
            if(visited[row][col]==1) {  // if same edge/land appears again then it should be ignored(or "continue" the loop) and pushback the previous output value , as if given a chance to move forward in the loop , it would disrupt the output variable
                ans.push_back(output); continue;
            }
            visited[row][col]=1;  // if once forward tin the loop , then it should not come again
            //matrix[row][col]=1;
            output++;  //increment output when query operators ask to change the mtarix value to 1 (land or island itself) as the algorithm considers every node to be disconnected initially 
            int adjr[]={-1,0,1,0};
            int adjc[]={0,1,0,-1};
            for(int a=0;a<4;a++){   // adjacent nodes in 4 directions
                int nrow=row+adjr[a];
                int ncol=col+adjc[a];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    if(visited[nrow][ncol]==1){
                        int node= row*m+col;  //node number row-wise
                        int n_node=nrow*m+ncol;
                    
                        if(ds.findParent(n_node)!=ds.findParent(node)){  // if they are not connected , then connect them and decrement output by 1 ( as the number connected islands has to be reduced by 1)
                            ds.UnionbySize(n_node,node);
                            output--;
                            
                        }
                    }
                }
            }
            ans.push_back(output);
        }
        return ans;
    }
    
    
};

// class DisjointSet {
//     vector<int> rank, parent, size;
// public:
//     DisjointSet(int n) {
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionByRank(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//         }
//         else if (rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u;
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };
// class Solution {
// private:
//     bool isValid(int adjr, int adjc, int n, int m) {
//         return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
//     }
// public:
//     vector<int> numOfIslands(int n, int m,
//                              vector<vector<int>> &operators) {
//         DisjointSet ds(n * m);
//         int vis[n][m];
//         memset(vis, 0, sizeof vis);
//         int cnt = 0;
//         vector<int> ans;
//         for (auto it : operators) {
//             int row = it[0];
//             int col = it[1];
//             if (vis[row][col] == 1) {
//                 ans.push_back(cnt);
//                 continue;
//             }
//             vis[row][col] = 1;
//             cnt++;
//             // row - 1, col
//             // row , col + 1
//             // row + 1, col
//             // row, col - 1;
//             int dr[] = { -1, 0, 1, 0};
//             int dc[] = {0, 1, 0, -1};
//             for (int ind = 0; ind < 4; ind++) {
//                 int adjr = row + dr[ind];
//                 int adjc = col + dc[ind];
//                 if (isValid(adjr, adjc, n, m)) {
//                     if (vis[adjr][adjc] == 1) {
//                         int nodeNo = row * m + col;
//                         int adjNodeNo = adjr * m + adjc;
//                         if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
//                             cnt--;
//                             ds.unionBySize(nodeNo, adjNodeNo);
//                         }
//                     }
//                 }
//             }
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
// };




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends