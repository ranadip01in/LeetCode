//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
//DP + Tabulation
//TC - O(n*w)
//SC - O(n*w)
    public:
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(w+1,0));
       for(int i=wt[0];i<=w;++i) dp[0][i]=val[0];
       for(int i=1;i<n;++i){
           for(int j=1;j<=w;++j){
               int notTake = dp[i-1][j];
                int take=0;
                if(j>=wt[i]) take = val[i] + dp[i-1][j-wt[i]];
                dp[i][j] = max(take,notTake);
           }
       }
       return dp[n-1][w];
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