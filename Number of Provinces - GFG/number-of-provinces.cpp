//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DSU{
public:
    vector<int> rank,parents,Size;
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
    void unionBySize(int u,int v){
        int ulp_v=findUPar(v);
        int ulp_u=findUPar(u);
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
class Solution {
public:
//TC - O(N^2)
//SC - O(N)
    int numProvinces(vector<vector<int>> isConnected, int n) {
        DSU ds(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isConnected[i][j]==1){
                    ds.unionByRank(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;++i){
            if(ds.findUPar(i)==i) ++cnt;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends