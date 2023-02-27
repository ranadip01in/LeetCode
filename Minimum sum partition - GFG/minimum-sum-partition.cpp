//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
//DP + Tabulation
//TC - O(n*k)
//SC - O(n*k)
  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;++i) sum+=nums[i];
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;++i) dp[i][0] = true;
        dp[0][nums[0]] = true;
        for(int i=1;i<n;++i){
            for(int j=1;j<=sum;++j){
                bool nonTake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i]) take = dp[i-1][j-nums[i]];
                dp[i][j] = take or nonTake;
            }
        }
        int mini=1e8;
        for(int s1=0;s1<=sum/2;++s1){
            if(dp[n-1][s1]) mini=min(mini,abs(sum-s1)-s1);
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends