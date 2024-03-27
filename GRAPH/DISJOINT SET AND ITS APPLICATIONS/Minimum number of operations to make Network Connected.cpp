// Number of Operations to Make Network Connected

// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<bits/stdc++.h>
using namespace std;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra_edges=0;
        DisjointSet ds(n);
        for(auto it: connections){
            int u=it[0], v=it[1];
            if(ds.findParent(u)!=ds.findParent(v)){
                ds.UnionbySize(u,v);
            }
            else extra_edges++;
        }
        int num_comps=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) num_comps++;
        }
        cout<<"extra:"<<extra_edges<<"  comps"<<num_comps<<endl;
        int ans=num_comps-1;// minimum number of edges required to connected all the components
        if(extra_edges>=ans) return ans;
        return -1;
        
    }
};