//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool countArrays(int idx,vector<int>&arr,vector<vector<int>>& dp,int sum){
        if(sum==0) return true;
        if(idx==0) return arr[0]==sum;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int notTake = countArrays(idx-1,arr,dp,sum);
        int take = false;
        if(arr[idx]<=sum) take = countArrays(idx-1,arr,dp,sum-arr[idx]);
        dp[idx][sum] = take||notTake;
        return dp[idx][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return countArrays(n-1,arr,dp,sum);
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