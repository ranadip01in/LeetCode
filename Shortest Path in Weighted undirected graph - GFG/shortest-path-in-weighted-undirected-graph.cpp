//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//TC - O(m*logn)
//SC - O(n)
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        set<pair<int,int>> st;
        st.insert({0,1});
        vector<int> parent(n+1),dist(n+1,1e9),path;
        std::iota(parent.begin(),parent.end(),0);
        dist[1]=0;
        while(!st.empty()){
            auto it = *(st.begin());
            int u = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto node:adj[u]){
                int v=node.first;
                int edgeWt=node.second;
                if(dis+edgeWt<dist[v]){
                    dist[v] = dis+edgeWt;
                    parent[v]=u;
                    st.insert({dist[v],v});
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends