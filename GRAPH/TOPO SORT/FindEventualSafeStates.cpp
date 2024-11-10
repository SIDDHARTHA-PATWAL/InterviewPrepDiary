// // // Find Eventual Safe States

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

//  https://leetcode.com/problems/find-eventual-safe-states/description/

// Example 1:

// Illustration of graph
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
// Example 2:

// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
// Explanation:
// Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 

// Constraints:

// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].length <= n
// 0 <= graph[i][j] <= n - 1
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].


// class Solution {
// public:
//     bool dfs_topo(int i,vector<int> vis,vector<vector<int>>& graph){
//         vis[i]=2;
//         for(auto node:graph[i]){
//             if(dfs_topo(node,vis,graph)==false) return false;
//             else if(vis[node]==2) return false;
//         }
//         vis[i]=1;
//         return true;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int m=graph.size();
//         vector<int> ans;
//         //vcetor<int> outdegree(m);
//         vector<int> vis(m,0);
//         for(int i=0;i<m;i++){
//             if(dfs_topo(i,vis,graph)==true) ans.push_back(i);
//             else if(graph[i].size()==1 && graph[i][0]==i){
//                     ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> reverseGraph(n, vector<int>());
        
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                reverseGraph[j].push_back(i);
                ++indegree[i];
            }
        }
        //queue can also be used in this , just the order of result before sorting may differ
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                st.push(i);
            }
        }
        
        vector<int> result;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            result.push_back(node);
            
            for (int neighbor : reverseGraph[node]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0) {
                    st.push(neighbor);
                }
            }
        }
        
        sort(result.begin(), result.end());  //tc=nlogn at worst case, as result may include all the vertices in toposort(ie all nodes are safe nodes)
        return result;
    }
};