// Minimum Spanning Tree

// Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//using Prim's algorithm
    int spanningTree(int V, vector<vector<int>> adj[])  //adj in input is adjacency list actually adj[node]={adjNode,wt}
    {
        // code here
        //unordered_set<pair<int,int>> st;  //if mst was asked but in htis case , we require only the sum
        priority_queue<pair<int, int>,
    	               vector<pair<int, int> >, greater<pair<int, int>>> pq; //{wt,node}   //if mst was asked then , {wt,node,parent}
        vector<int> vis(V,0);
        //{wt,node}
        pq.push({0,0});//{wt,node}    // if mst was aksed then , {0,0,-1}
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node= it.second;
            int wt=it.first;
            if (vis[node] == 1) continue;
    			// add it to the mst virtually
    			vis[node] = 1;
    			sum += wt;
            	for (auto it : adj[node]) {
    				int adjNode = it[0];
    				int edW = it[1];
    				if (!vis[adjNode]) {
    					pq.push({edW, adjNode});
    				}
    			}
    		
        }
        return sum;
        
    }

	 //using Kruskal's algorithm
        int findParent(int node,vector<int> &parent){
            if(node==parent[node]) return node;
            return parent[node]=findParent(parent[node],parent);
        }
        void UnionbyRank(int u ,int v,vector<int> &parent,vector<int>&rank){
            int ult_u=findParent(u,parent);
            int ult_v=findParent(v,parent);
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
        void UnionbySize(int u ,int v,vector<int> &parent,vector<int>&size){
            int ult_u=findParent(u,parent);
            int ult_v=findParent(v,parent);
            if(ult_u!=ult_v){
                if(size[ult_u]>=size[ult_v]){
                    parent[ult_v]=ult_u; size[ult_u]++;
                }
                else if(size[ult_u]<size[ult_v]){
                    parent[ult_u]=ult_v; size[ult_v]++;
                }
            }
        }
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int,pair<int,int>>> edges;
        //no need to worry about the bidirectional edges pushed two times apprarently as disjoint set will ignore it
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int adjNode =it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});  //{wt,{node,adjNode}}
            }
        }
        sort(edges.begin(),edges.end());
        int mstsum=0;
        vector<int>parent(V),size(V,1);
        for(int i=0;i<V;i++){
                parent[i]=i;
            }
        for(auto it:edges){
            int node=it.second.first;
            int adjNode= it.second.second;
            int edw=it.first;
            if(findParent(node,parent)!=findParent(adjNode,parent)){
                UnionbySize(node,adjNode,parent,size);
                mstsum+=edw;
            }
        }
        return mstsum;
        
    }
    
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends