//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
//TC - O(V+E)
//SC - O(V+E)
    void dfs(int u,vector<int>& vis,vector<vector<int>>& adj,stack<int> &st){
        vis[u]=1;
        for(int v:adj[u]){
            if(!vis[v]) dfs(v,vis,adj,st);
        }
        st.push(u);
    }
    void dfs1(int u,vector<int>& vis,vector<vector<int>>& adjT){
        vis[u]=1;
        for(int v:adjT[u]){
            if(!vis[v]) dfs1(v,vis,adjT);
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>vis(V,0);
        stack<int> st;
        for(int i=0;i<V;++i){
            if(!vis[i]) dfs(i,vis,adj,st);
        }
        vector<vector<int>> adjT(V,vector<int>());
        for(int i=0;i<V;++i){
            vis[i]=0;
            for(int v:adj[i]) adjT[v].push_back(i);
        }
        int ssc=0;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                dfs1(i,vis,adjT);
                ssc+=1;
            }
        }
        return ssc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends