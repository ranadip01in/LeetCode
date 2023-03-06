//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
//DP + Tabulation
//TC - O(n*n)
//SC - O(n*n)
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=1;i<=n;++i) dp[0][i]=i*price[0];
        for(int i=1;i<n;++i){
            for(int j=1;j<=n;++j){
                int notTake = dp[i-1][j];
                int take=0;
                if(i+1<=j) take = price[i] + dp[i][j-i-1];
                dp[i][j] = max(take,notTake);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends