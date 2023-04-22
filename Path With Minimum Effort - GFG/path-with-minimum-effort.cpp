//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//N - n*m
//TC - O(ElogN)
//SC - O(N)
    int MinimumEffort(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> minEffort(n,vector<int>(m,1e9));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        minEffort[0][0]=0;
        while(!st.empty()){
            auto it = *(st.begin());
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            st.erase(it);
            for(int i=0;i<4;++i){
                int nrow = dx[i]+row;
                int ncol = dy[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int newEffort = max(effort,abs(heights[row][col]-heights[nrow][ncol]));
                    if(newEffort<minEffort[nrow][ncol]){
                        minEffort[nrow][ncol] = newEffort;
                        st.insert({minEffort[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return minEffort[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends