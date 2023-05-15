//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
//TC - O(V+2E)
//SC - O(V)
    void dfs(int& timer,int node,int parent,vector<int> &vis,int tin[],int low[],vector<int> &mark,vector<int>adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer+=1;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(timer,it,node,vis,tin,low,mark,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child+=1;
            }else{
                low[node]=min(low[node],tin[it]);
            }   
        }
        if(child>1 && parent==-1) mark[node]=1;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V,0);
        int tin[V];
        int low[V];
        vector<int> mark(V,0);
        int timer=0;
        for(int i=0;i<V;++i){
            if(!vis[i]) dfs(timer,i,-1,vis,tin,low,mark,adj);
        }
        vector<int> ans;
        for(int i=0;i<V;++i){
            if(mark[i]) ans.push_back(i);
        }
        if(ans.empty()) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends