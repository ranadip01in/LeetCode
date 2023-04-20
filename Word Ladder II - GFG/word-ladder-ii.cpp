//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
//Sol - 1
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        set<string> st(wordList.begin(),wordList.end());
        for(auto it:wordList) st.insert(it);
        st.erase(beginWord);
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> used;
        used.push_back(beginWord);
        int level=0;
        while(!q.empty()){
            vector<string>tmp=q.front();
            q.pop();
            //erase all words that has been used
            //used in the previous levels to transform
            if(tmp.size()>level){
                level+=1;
                for(auto it:used) st.erase(it);
                // used.clear();
            }
            string word=tmp.back();
            if(word==endWord){
                if(ans.size()==0) ans.push_back(tmp);
                else if(ans[0].size()==tmp.size()) ans.push_back(tmp);
            }
            for(int i=0;i<word.length();++i){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        tmp.push_back(word);
                        q.push(tmp);
                        //mark as visited on the level
                        used.push_back(word);
                        tmp.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends