//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
//DP + Memoization
//TC - O(n*n)
//SC - O(n*n)
    int maxProfit(int idx,int n,int price[],vector<vector<int>> &dp){
        if(n==0) return 0;
        if(idx==0) return n*price[0];
        if(dp[idx][n]!=-1) return dp[idx][n];
        int notTake = maxProfit(idx-1,n,price,dp);
        int take=0;
        if(idx+1<=n) take = price[idx] + maxProfit(idx,n-idx-1,price,dp);
        dp[idx][n] = max(take,notTake);
        return dp[idx][n];
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return maxProfit(n-1,n,price,dp);
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