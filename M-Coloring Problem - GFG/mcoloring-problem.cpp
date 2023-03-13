//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
//TC - O(m^n)
//SC - O(n)
    bool isValid(int node,int col,bool graph[101][101],int color[], int m, int n){
        for(int edge=0;edge<n;++edge){
            if(edge!=node && graph[node][edge]){
                if(color[edge]==col) return false;
            }
        }
        return true;
    }
    bool solve(int node,bool graph[101][101],int color[], int m, int n){
        if(node==n) return true;
        for(int i=1;i<=m;++i){
            if(isValid(node,i,graph,color,m,n)){
                color[node]=i;
                if(solve(node+1,graph,color,m,n)) return true;
                color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n];
        if(solve(0,graph,color,m,n)) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends