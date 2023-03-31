//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
//TC - O(R*LogC*Log(2000))
    int check(vector<vector<int>> &matrix, int R, int C,int mid){
        int cnt=0;
        for(int i=0;i<R;++i){
            int left=0,right=C-1;
            while(left<=right){
                int mid1 = (left+right)/2;
                if(matrix[i][mid1]>mid) right=mid1-1;
                else left=mid1+1;
            }
            cnt+=left;
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int left=1,right=2000;
        int median = (R*C)/2;
        while(left<=right){
            int mid = (left+right)/2;
            if(check(matrix,R,C,mid)>median) right=mid-1;
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