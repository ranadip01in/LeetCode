//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
//TC - O(R*C*Log(2000))
    int check(vector<vector<int>> &matrix, int R, int C,int mid){
        int cnt=0;
        for(auto row:matrix){
            for(auto col:row) if(col<=mid) ++cnt;
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int left=1,right=2000;
        int total = R*C;
        while(left<=right){
            int mid = (left+right)/2;
            if(check(matrix,R,C,mid)>total/2) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends