//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//TC - O(N)(NODE) + O(N+2E)(BFS)
//SC - O(N)(COLOR) + O(N)(QUE)
    bool bfs(int start,vector<int> graph[],vector<int>&color){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjacentNode:graph[node]){
                if(color[adjacentNode]==-1){
                    color[adjacentNode]=1-color[node];
                    q.push(adjacentNode);
                }else if(color[adjacentNode]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int n=V;
        vector<int> color(n,-1);
        for(int i=0;i<n;++i){
            if(color[i]==-1){
                if(bfs(i,adj,color)==false) return false;
            }
        }
        return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends