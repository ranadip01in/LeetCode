//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DSU{
    vector<int> rank,parents;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parents.resize(n+1,0);
        for(int a=0;a<=n;++a) parents[a]=a;
    }
    int findUPar(int n){
        if(n==parents[n]) return n;
        return parents[n]=findUPar(parents[n]);
    }
    void unionByRank(int u,int v){
        int ulp_v=findUPar(v);
        int ulp_u=findUPar(u);
        if(ulp_v==ulp_u) return;
        if(rank[ulp_u]<rank[ulp_v]) parents[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u]) parents[ulp_v]=ulp_u;
        else{
            parents[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution{
public:
//TC - O(N^2*logN)
//SC - O(N^2)
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;++i){
            for(int j=1;j<accounts[i].size();++j){
                string mail = accounts[i][j];
                if(mp.find(mail)==mp.end()) mp[mail]=i;
                else {
                    int v = mp[mail];
                    int u = i;
                    ds.unionByRank(u,v);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto it:mp){
            int v = ds.findUPar(it.second);
            string mail = it.first;
            mergeMail[v].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;++i){
            auto st=mergeMail[i];
            if(st.empty()) continue;
            sort(st.begin(),st.end());
            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            for(auto it:st) tmp.push_back(it);
            ans.push_back(tmp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends