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
        vector<bool> dp(sum+1,false),curr(sum+1);
        dp[0]=curr[0]=1;
        dp[nums[0]]=1;
        for(int i=1;i<n;++i){
            for(int j=1;j<=sum;++j){
                bool nonTake = dp[j];
                bool take = false;
                if(j>=nums[i]) take = dp[j-nums[i]];
                curr[j] = take or nonTake;
            }
            dp=curr;
        }
        return dp[sum];
        
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