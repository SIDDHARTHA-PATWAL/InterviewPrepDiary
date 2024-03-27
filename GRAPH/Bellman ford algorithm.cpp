// Distance from the Source (Bellman-Ford Algorithm)

// Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
// Note: If the Graph contains a negative cycle then return an array consisting of only -1.

// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S]=0;
        //ExV
        for(int count=1;count<=V-1;count++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]+wt<dist[v]) dist[v]=dist[u]+wt;
            }
        }
        //nth relaxation iteration to check negative cycle
        for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]+wt<dist[v]) {
                    dist[v]=dist[u]+wt;
                    return{-1};
                }
        }
        return dist;
    }
};