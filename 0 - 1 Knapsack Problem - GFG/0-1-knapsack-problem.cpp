//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
//DP+Memoization
//TC - O(n*w)
//SC - O(n*w)
    public:
    int maxItem(int idx,int w,int wt[], int val[],vector<vector<int>> &dp){
        if(idx==0){
            if(wt[0]<=w) return val[0];
            return 0;
        }
        if(dp[idx][w]!=-1) return dp[idx][w];
        int notTake = maxItem(idx-1,w,wt,val,dp);
        int take=0;
        if(w>=wt[idx]) take = val[idx] + maxItem(idx-1,w-wt[idx],wt,val,dp);
        dp[idx][w] = max(take,notTake);
        return dp[idx][w];
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(w+1,-1));
       return maxItem(n-1,w,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends