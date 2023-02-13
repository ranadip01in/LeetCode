//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
//DP + Memoization
//TC - O(N)
//SC - O(N)
//Find best subsequence sum [0..idx]
    public:
    //Function to find the maximum money the thief can get.
    int robHouse(int idx,int nums[],int dp[]){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = robHouse(idx-2,nums,dp) + nums[idx];
        int nonPick = robHouse(idx-1,nums,dp);
        dp[idx] = max(pick,nonPick);
        return dp[idx];
    }
    int FindMaxSum(int nums[], int n)
    {
        // Your code here
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return robHouse(n-1,nums,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends