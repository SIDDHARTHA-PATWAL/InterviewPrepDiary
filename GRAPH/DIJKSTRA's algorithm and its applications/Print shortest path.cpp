// Shortest Path in Weighted undirected graph

// You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int parent[n+1];
        for(int i=1;i<n+1;i++){
            parent[i]=i; //each vertex is parent of themselves initially
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[1]=0;
        pq.push({0,1});
        //O(ElogV)  time complexity
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjweight=it.second;
                int adjnode=it.first;
                if(dist[node]+adjweight<dist[adjnode]){  // if(distance+adjweight<dist[adjnode])
                    dist[adjnode]=dist[node]+adjweight;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int>path;
        int node=n;
        //O(N)  time complexity
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends