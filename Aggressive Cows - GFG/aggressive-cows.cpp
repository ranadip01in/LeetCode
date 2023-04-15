//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
//TC - O(nlogn)
//SC - O(1)
    int check(vector<int>&stalls,int n,int k,int mid){
        int cnt=1,place=stalls[0];
        for(int i=1;i<n;++i){
            if(stalls[i]-place>=mid){
                cnt+=1;
                place=stalls[i];
            }
        }
        return cnt>=k;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int left=1,right=stalls[n-1]-stalls[0];
        int ans=0;
        while(left<=right){
            int mid = (left+right)/2;
            if(check(stalls,n,k,mid)) ans=mid,left=mid+1;
            else right=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends