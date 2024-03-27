// Find the City With the Smallest Number of Neighbors at a Threshold Distance

// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj_matrix(n,vector<int>(n,1e9));
        for(auto it:edges){
            adj_matrix[it[0]][it[1]]=it[2];
            adj_matrix[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) adj_matrix[i][j]=0;
        }
        }
        for(int via=0;via<n;via++){
           for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj_matrix[i][j]=min(adj_matrix[i][j],
                                        adj_matrix[i][via]+adj_matrix[via][j]);
                }
            } 
        }
        int curr=1e9,ans=n-1;
        for(int city=0;city<n;city++){
            int count=0;
            for(int x=0;x<n;x++){
                if(city==x) continue;
                if(adj_matrix[city][x]>0 && adj_matrix[city][x]<1e9 && adj_matrix[city][x]<=distanceThreshold){
                    count++;
                }
            }
            if(curr>=count){  curr=count; ans=city;}
        }
        return ans;
    }
};