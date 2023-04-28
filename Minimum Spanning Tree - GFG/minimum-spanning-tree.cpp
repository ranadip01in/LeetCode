//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class DSU{
    vector<int> rank,parents,Size;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parents.resize(n+1,0);
        Size.resize(n+1,1);
        for(int i=0;i<=n;++i) parents[i]=i;
    }
    int findUPar(int n){
        if(n==parents[n]) return n;
        return parents[n]=findUPar(parents[n]);
    }
    void unionByRank(int u,int v){
        int ulp_v=parents[v];
        int ulp_u=parents[u];
        if(ulp_v==ulp_u) return;
        if(rank[ulp_u]<rank[ulp_v]) parents[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u]) parents[ulp_v]=parents[ulp_u];
        else{
            parents[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_v=parents[v];
        int ulp_u=parents[u];
        if(ulp_u==ulp_v) return;
        if(Size[ulp_u]<Size[ulp_v]){
            parents[ulp_u]=ulp_v;
            Size[ulp_v]+=Size[ulp_u];
        }else{
            parents[ulp_v]=ulp_u;
            Size[ulp_u]+=Size[ulp_v];
        }
    }
};
class Solution
{
//TC - O(M*4*alpha*2)
//SC - O(M)
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        //TC - O(V+E)
        for(int i=0;i<V;++i){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        //TC - O(MlogM)
        sort(edges.begin(),edges.end());
        DSU ds(V);
        int mstWt=0;
        //TC - O(M*4*alpha)
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstWt+=wt;
                ds.unionByRank(u,v);
            }
        }
        return mstWt;
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