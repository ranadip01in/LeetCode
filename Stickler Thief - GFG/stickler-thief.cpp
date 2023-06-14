//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int loot(int arr[],vector<int> &dp,int idx){
        if(idx<0) return 0;
        if(idx==0) return arr[0];
        if(dp[idx]!=-1) return dp[idx];
        int left = arr[idx]+loot(arr,dp,idx-2);
        int right = loot(arr,dp,idx-1);
        return dp[idx]=max(left,right);
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n,-1);
        return loot(arr,dp,n-1);
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