//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
//TC - O(ElogV)
//SC - O(V)
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        set<pair<int,int>> st;
        // {wt,node}
        st.insert({0,0});
        int sum=0;
        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            int node = it.second;
            int wt = it.first;
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            for(auto iter:adj[node]){
                int adjNode = iter[0];
                int adjWt = iter[1];
                if(!vis[adjNode]) st.insert({adjWt,adjNode});
            }
        }
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends