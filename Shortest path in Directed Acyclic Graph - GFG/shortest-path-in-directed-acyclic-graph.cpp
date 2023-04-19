//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
//TC - O(N+M)
//SC - O(M)
    void topoSort(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &s){
        vis[node]=1;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode.first]) topoSort(adjNode.first,adj,vis,s);
        }
        s.push(node);
    }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
         vector<pair<int,int>> adj[n];
         for(int i=0;i<m;++i){
             int u=edges[i][0];
             int v=edges[i][1];
             int wt=edges[i][2];
             adj[u].push_back({v,wt});
         }
         //toposort
         stack<int> s;
         int vis[n]={0};
         for(int i=0;i<n;++i){
             if(!vis[i]) topoSort(i,adj,vis,s);
         }
         //distance thing O(N+M)
         vector<int> dist(n,1e9);
         dist[0]=0;
         while(!s.empty()){
             int node=s.top();
             s.pop();
             for(auto it:adj[node]){
                 int v=it.first;
                 int wt=it.second;
                 if(dist[node]+wt<dist[v]) dist[v]=dist[node]+wt;
             }
         }
         for(int i=0;i<n;++i){
             if(dist[i]==1e9) dist[i]=-1;
         }
         return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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