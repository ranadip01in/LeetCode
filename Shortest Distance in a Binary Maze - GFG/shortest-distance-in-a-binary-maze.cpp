//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
//N - n*m
//TC - O(N*4)
//SC - O(N)
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        int n=grid.size(),m=grid[0].size();
        if(grid[source.first][source.second]==0 || grid[destination.first][destination.second]==0) return -1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        queue<pair<int,pair<int,int>>> st;
        st.push({0,{source.first,source.second}});
        while(!st.empty()){
            auto it = st.front();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            st.pop();
            if(row==destination.first && col==destination.second) return dis;
            for(int i=0;i<4;++i){
                int nrow = dx[i]+row;
                int ncol = dy[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]){
                    if(dis+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=dis+1;
                        st.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends