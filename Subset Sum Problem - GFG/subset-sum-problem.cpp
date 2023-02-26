//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
//DP + Memoization
//TC - O(n*k)
//SC - O(n*k)
    bool checkSubArray(int idx,int k,vector<int>& nums,vector<vector<int>> &dp){
        if(k==0) return true;
        if(idx==0) return nums[0]==k;
        if(dp[idx][k]!=-1) return dp[idx][k];
        bool nonTake = checkSubArray(idx-1,k,nums,dp);
        bool take = false;
        if(k>=nums[idx] && nums[idx]!=0) take = checkSubArray(idx-1,k-nums[idx],nums,dp);
        dp[idx][k] = take or nonTake;
        return dp[idx][k];
    }
    bool isSubsetSum(vector<int>nums, int sum){
        int n = nums.size();
        vector<vector<int>> dp(102,vector<int>(1e5+2,-1));
        return checkSubArray(n-1,sum,nums,dp);
        
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