// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int ,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }   
        vector<int> dist(n,1e9);
        dist[src]=0;
        //no need of priority queue as stops increase by +1 and enter in a  increasing order , so whoever comes out of the queue first is the smallest implicity
        //{stops,{node,dist}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        //E= flights.size();
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue; //if stops exceeded the maximum no. of stops given to us, no need to go to any further adjacency list, and drop it
            for(auto iter: adj[node]){
                int adjNode=iter.first;
                int edge_weight=iter.second;
                if(cost+edge_weight<dist[adjNode] && stops<=k){ //if(cost+edge_weight<dist[adjNode])  //also excutable
                    dist[adjNode]=cost+edge_weight;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};