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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n); // representing accounts(including accounts of same person also) as nodes  and making them unconnected initially , 
        // connected accountts or nodes would mean that they are are of same person
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            int m=accounts[i].size();
            for(int j=1;j<m;j++){
                string email=accounts[i][j];
                // if node does not exist
                if(mp.find(email)==mp.end()){
                    mp[email]=i;  //i is the node for current step
                }
                else{ // if node aready exist in map, then the current i has to be connnected with map value of ecurrent mail through the disjoint set
                    ds.UnionbyRank(mp[email],i);
                }
            }
        }
        vector<string> mergedaccounts[n];
        //vector<vector<string>> mergedaccounts(n);

        //iterating over map , and merging the accounts
        for(auto it: mp){
            string email=it.first;
            int node=ds.findParent(it.second);
            mergedaccounts[node].push_back(email);
        }
        // rearranging the answer
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedaccounts[i].size()==0) continue;
            sort(mergedaccounts[i].begin(),mergedaccounts[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedaccounts[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};