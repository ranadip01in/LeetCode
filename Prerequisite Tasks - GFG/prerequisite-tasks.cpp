//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//TC - O(N+E)(BFS)
//SC - O(N)(QUE) + O(N)(inDegree) + O(N)(topo)
	bool isPossible(int numCourses, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it.first].push_back(it.second);
        }
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<numCourses;++i){
            for(auto it:adj[i]) inDegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        return topo.size()==numCourses;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends