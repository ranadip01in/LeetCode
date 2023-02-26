//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
//DP + Tabulation
//TC - O(n*k)
//SC - O(n*k)
    bool isSubsetSum(vector<int>nums, int sum){
        int n = nums.size();
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
        return dp[n-1][sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends