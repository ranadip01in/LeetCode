//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DSU{
public:
    vector<int> rank,parents;
    DSU(int n){
        rank.resize(n+1,0);
        parents.resize(n+1,0);
        for(int a=0;a<=n;++a) parents[a]=a;
    }
    int findUPar(int n){
        if(n==parents[n]) return n;
        return parents[n]=findUPar(parents[n]);
    }
    void unionByRank(int u,int v){
        int ulp_v=findUPar(v);
        int ulp_u=findUPar(u);
        if(ulp_v==ulp_u) return;
        if(rank[ulp_u]<rank[ulp_v]) parents[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u]) parents[ulp_v]=ulp_u;
        else{
            parents[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
//TC - O(N*4*alpha*2)
//SC - O(N)
    int Solve(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int extraEdges=0;
        for(auto it:connections){
            int u=it[0],v=it[1];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionByRank(u,v);
            }else{
                ++extraEdges;
            }
        }
        int graphComponent=0;
        for(int i=0;i<n;++i){
            if(ds.parents[i]==i) ++graphComponent;
        }
        int edgeNeed=graphComponent-1;
        if(edgeNeed<=extraEdges) return edgeNeed;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends