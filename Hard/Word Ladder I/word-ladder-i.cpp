//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
     //ye dekhna kyu BFS lga ar DFS ni
     queue<pair<string,int>> q;
     unordered_set<string> st(wordList.begin(),wordList.end());
     q.push({startWord,1});
     st.erase(startWord);
     int steps=0;
     while(!q.empty()){
         string word=q.front().first;
         steps=q.front().second;
         q.pop();
         if(word==targetWord){return steps;}
         for(int i=0;i<word.length();i++){
             char og=word[i];
             for(char c='a';c<='z';c++){
               word[i]=c;
               if(st.find(word) !=st.end()){
                   st.erase(word);
                   q.push({word,steps+1});}
             }
             word[i]=og;
         }
     }
     return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends