//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int firstDigit(int x){
        while(x>=10) x/=10;
        return x;
    }
    int numbersInRange(int L, int R){
        // code here 
        if(L>R) return 0;
        L-=1;
        int a=R/10;
        int b=L/10;
        if(R>9) a+=9;
        else a=R;
        if(L>9) b+=9;
        else b=L;
        if(firstDigit(R)>R%10) a-=1;
        if(firstDigit(L)>L%10) b-=1;
        return a-b;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout << ob.numbersInRange(L, R) << endl;
    }
    return 0; 
} 

// } Driver Code Ends