//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
//TC - O(V+2E)*LogV
//SC - O(V)
//using Set
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,1e9);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<pair<int,int>> st;
        st.insert({0,S});
        while(!st.empty()){
            int u = st.begin()->second;
            int dis = st.begin()->first;
            st.erase({dis,u});
            for(auto it:adj[u]){
                int v = it[0];
                int edgeWt = it[1];
                if(dis+edgeWt<dist[v]){
                    dist[v]=dis+edgeWt;
                    st.insert({dist[v],v});
                }
            }
        }
        return dist;
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


// } Driver Code Ends