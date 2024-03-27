#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
//using priority queue
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        priority_queue <pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        dist[S]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjweight=it[1];
                int adjnode=it[0];
                if(dist[node]+adjweight<dist[adjnode]){
                    dist[adjnode]=dist[node]+adjweight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
        
    }
//using set data struture
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        set<pair<int,int>> st;
        st.insert({0,S});
        dist[S]=0;
        while(!st.empty()){
           auto it=*(st.begin()); //dereferencing the pointer to the first element in the set;
           int node=it.second;
           int distance=it.first;
           st.erase(it);
            for(auto it: adj[node]){
                int adjweight=it[1];
                int adjnode=it[0];
                if(dist[node]+adjweight<dist[adjnode]){
                    //erase if existed earlier and we have found a shorter path
                    if(dist[adjnode]!=1e9) st.erase({dist[adjnode],adjnode});
                    dist[adjnode]=dist[node]+adjweight;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
        
    }
};
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
