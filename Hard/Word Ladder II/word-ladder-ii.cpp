//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
     vector<vector<string>> ans;
     vector<string> UsedOnPreviousLevel;
     queue<vector<string>> q;
     unordered_set<string> st(wordList.begin(),wordList.end());
     q.push({beginWord});
     UsedOnPreviousLevel.push_back(beginWord);
     int level=0;
     while(!q.empty()){
         vector<string> v=q.front();
         q.pop();
         //erase all words that has been used in previous level of transformation
         if(v.size()>level){
             level++;
             for(auto it : UsedOnPreviousLevel){st.erase(it);}
         }
         string word=v.back();
         if(word==endWord){
            if(ans.size()==0 || ans[0].size()==v.size()) {ans.push_back(v);}
         }
         for(int i=0;i<word.length();i++){
             char og=word[i];
             for(char c='a';c<='z';c++){
               word[i]=c;
               if(st.find(word) !=st.end()){
                   UsedOnPreviousLevel.push_back(word);
                   v.push_back(word);
                   q.push(v);
                   v.pop_back();}
             }
             word[i]=og;
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