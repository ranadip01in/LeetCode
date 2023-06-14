//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int loot(int arr[],vector<int> &dp,int idx){
        if(idx<0) return 0;
        if(idx==0) return arr[0];
        if(dp[idx]!=-1) return dp[idx];
        int left = arr[idx]+loot(arr,dp,idx-2);
        int right = loot(arr,dp,idx-1);
        return dp[idx]=max(left,right);
    }
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
        return loot(arr,dp,n-1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends