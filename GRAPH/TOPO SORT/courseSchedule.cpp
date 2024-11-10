// // // COURSE SCHEDULE 1

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// https://leetcode.com/problems/course-schedule/description/

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //repesenting as a DAG graph
        vector<vector<int>> graph(numCourses);
        for(auto it : prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        //storing indegree of each and every vertices
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it: graph[i]){
                indegree[it]++;
            }
        }
        //implementing topo sort using bfs  //  can use dfs but for answering yes or no only and not for storing the topo
        vector<int> topo;
        queue <int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node =q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:graph[node] ){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        //if toposort is successfull(thus no cyclic dependencies ), then then the size of topo will be same as number of  vertices 
        if(topo.size()==numCourses) return true;
        return false;
    }
};