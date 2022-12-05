//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int parent,vector<int>&vis,vector<int> adj[]){
        vis[node]=1;
        bool hasCycle=false;
        for(auto adjacentNode:adj[node]){
            if(!vis[adjacentNode]) hasCycle|=dfs(adjacentNode,node,vis,adj);
            else if(adjacentNode!=parent) return true;
        }
        return hasCycle;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
        bool hasCycle=false;
        for(int i=0;i<V;++i){
            if(!vis[i]){
                hasCycle|=dfs(i,-1,vis,adj);
            }
        }
        return hasCycle;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends