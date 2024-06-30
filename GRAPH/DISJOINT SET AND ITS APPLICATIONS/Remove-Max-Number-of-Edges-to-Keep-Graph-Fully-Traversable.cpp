//  //  Remove Max Number of Edges to Keep Graph Fully Traversable

// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/

// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

// Constraints:

// 1 <= n <= 105
// 1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
// edges[i].length == 3
// 1 <= typei <= 3
// 1 <= ui < vi <= n
// All tuples (typei, ui, vi) are distinct.


//SOLTUTION 1
class DisjointSet{
    public: 
        vector<int>parent,rank,size;
        DisjointSet(int n){
            rank.resize(n+1,0);
            // size.resize(n+1,1);
            parent.resize(n+1);
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
                    parent[ult_v]=ult_u; size[ult_u]+=size[ult_v];
                }
                else if(size[ult_u]<size[ult_v]){
                    parent[ult_u]=ult_v; size[ult_v]+ =size[ult_u];
                }
            }
        }
    
};
class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

          THIS SOLUTION PASSED BUT EXCEEDS SOME PREFERRED LIMIT ON TIME

        // int M =edges.size();
        // TC->O( M*4*ALPHA(N))  SC->O(4*N)  
        DisjointSet alice(n);
        DisjointSet bob(n);
        int removed_edges=0;
        // sort(edges.begin(),edges.end(),greater<vector<int>>());

        for(auto it: edges){
            if(it[0]==3){
                int u_a = alice.findParent(it[1]);
                int v_a = alice.findParent(it[2]);
                int u_b = bob.findParent(it[1]);
                int v_b = bob.findParent(it[2]);
                if(u_a!=v_a || u_b!=v_b){  // u_a!=v_a && u_b!=v_b willl also be correct
                                        //   because when u_a!=v_a will be TRUE then u_b!=v_b will also be TRUE
                                        //there will not be a case when ALICE removes some edge but it is required by BOB
                                        //When ALICE requires some edge ,then it is also required by BOB.
                  alice.UnionbyRank(u_a,v_a);
                  bob.UnionbyRank(u_b,v_b);
                }
                else removed_edges++;
            }
        }

        //IN THIS ,THE REMOVED EDGES BY BOTH ALICE AND BOB DON'T HAVE A COMMON.
        for(auto it:edges){
            if(it[0]==1){
                int u = alice.findParent(it[1]);
                int v = alice.findParent(it[2]);
                if(u!=v){
                  alice.UnionbyRank(u,v);
                }
                else removed_edges++;
            }
            if(it[0]==2){
                int u = bob.findParent(it[1]);
                int v = bob.findParent(it[2]);
                if(u!=v){
                  bob.UnionbyRank(u,v);
                }
                else removed_edges++;
            }
        }
      
        // Check if Alice and Bob can traverse all nodes
        int aliceParent = alice.findParent(1);
        int bobParent = bob.findParent(1);
        for (int i=2;i<=n;i++) {
            if (alice.findParent(i)!= aliceParent || bob.findParent(i) != bobParent) {
                return -1;
            }
        }

        return removed_edges;
    }
};

//SOLUTION 2
class DisjointSet{
    public: 
        vector<int>parent,rank,size;
        int connections=0;
        DisjointSet(int n){
            rank.resize(n+1,0);
            // size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        bool isConnected(int n){
            return (connections==n-1);
        }
        int findParent(int node){
            if(node==parent[node]) return node;
            return parent[node]=findParent(parent[node]);
        }
        bool UnionbyRank(int u ,int v){
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
                connections++;
                return true;
            }
            else return false;
        }
        bool UnionbySize(int u ,int v){
            int ult_u=findParent(u);
            int ult_v=findParent(v);
            if(ult_u!=ult_v){
                if(size[ult_u]>=size[ult_v]){
                    parent[ult_v]=ult_u; size[ult_u]+=size[ult_v];
                }
                else if(size[ult_u]<size[ult_v]){
                    parent[ult_u]=ult_v; size[ult_v]+= size[ult_u];
                }
                connections++;
                return true;
            }
            else return false;
        }
    
};
class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // int M =edges.size();
        // TC->O( M*4*ALPHA(N))  SC->O(4*N)  
        DisjointSet alice(n);
        DisjointSet bob(n);
        int removed_edges=0;

        for(auto it: edges){
            if(it[0]==3){
                if( !alice.UnionbyRank(it[1],it[2]) || !bob.UnionbyRank(it[1],it[2])){  
                   removed_edges++;     
                }
            }
        }

        //IN THIS ,THE REMOVED EDGES BY BOTH ALICE AND BOB DON'T HAVE A COMMON.
        for(auto it:edges){
            if(it[0]==1){
                if(!alice.UnionbyRank(it[1],it[2])){
                    removed_edges++;
                }
            }
            if(it[0]==2){
                if(!bob.UnionbyRank(it[1],it[2])){
                  removed_edges++;
                }
            }
        }
      
        // Check if Alice and Bob can traverse all nodes
        if (!alice.isConnected(n)|| !bob.isConnected(n) ) {
            return -1;
        }

        return removed_edges;
    }
};
