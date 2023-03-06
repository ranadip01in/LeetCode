//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
//DP + Memoization
//TC - O(n*w)
//SC - O(n*w)
    int maxProfit(int idx,int w,int val[],int wt[],vector<vector<int>>& dp){
        if(w==0) return 0;
        if(idx==0) return (w/wt[0])*val[0];
        if(dp[idx][w]!=-1) return dp[idx][w];
        int notTake = maxProfit(idx-1,w,val,wt,dp);
        int take=0;
        if(wt[idx]<=w) take = val[idx] + maxProfit(idx,w-wt[idx],val,wt,dp);
        dp[idx][w] = max(take,notTake);
        return dp[idx][w];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return maxProfit(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends