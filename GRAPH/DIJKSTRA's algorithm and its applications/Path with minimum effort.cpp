#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Code here
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int adjr[]={-1,0,1,0};
        int adjc[]={0,1,0,-1};
        //ElogV- time complexity of dijkstra's algo for general graph 
        //nxmx4 xlog( n X m)
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int row=it.second.first;
            int col=it.second.second;
            int diff=it.first;
            //if(diff>dist[row][col])continue;
            //it can be returned because no further better path will come AS even if some diff comes smaller than our asnwer then also the max effort of that new path can't be less than the our answer effort which is the minimum of ALL
            if(row==m-1 && col==n-1) return diff;
            for(int i=0;i<4;i++){
                int nrow=row+adjr[i];
                int ncol=col+adjc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    int new_effort=max(diff,abs(heights[nrow][ncol]-heights[row][col]));
                    if(new_effort<dist[nrow][ncol]){
                        dist[nrow][ncol]=new_effort;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
                
            }
        }
        return 0;//unreachable
    }
    //using visited array instead of dist or heights array
    // int minimumEffortPath(vector<vector<int>>& heights) {
    //     int m = heights.size();
    //     int n = heights[0].size();
        
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));
        
    //     auto cmp = [](const auto& a, const auto& b) {
    //         return a[2] > b[2];
    //     };
    //     priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
    //     pq.push({0, 0, 0});
        
    //     int adjr[] = {-1, 0, 1, 0};
    //     int adjc[] = {0, 1, 0, -1};
        
    //     while (!pq.empty()) {
    //         auto curr = pq.top();
    //         pq.pop();
            
    //         int row = curr[0];
    //         int col = curr[1];
    //         int diff = curr[2];
            
    //         if (visited[row][col])
    //             continue;
            
    //         visited[row][col] = true;
            
    //         if (row == m - 1 && col == n - 1)
    //             return diff;
            
    //         for (int i = 0; i < 4; i++) {
    //             int nrow = row + adjr[i];
    //             int ncol = col + adjc[i];
                
    //             if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]) {
    //                 int new_effort = max(diff, abs(heights[nrow][ncol] - heights[row][col]));
    //                 pq.push({nrow, ncol, new_effort});
    //             }
    //         }
    //     }
        
    //     return 0; // unreachable
    // }
};
