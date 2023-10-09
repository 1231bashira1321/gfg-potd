//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	 vector<vector<int>> adj(N);
        for(auto it : prerequisites){
            adj[it.second].push_back(it.first);
        }
	 int indegree[N]={0};
      for(int i=0;i<N;i++){
       for(auto it : adj[i]){
           indegree[it]++;
       }  
      }
       queue<int> q;
      for(int i=0;i<N;i++){
          if(indegree[i]==0){q.push(i);}
      }
     int v=0;
     while(!q.empty()){
      int x=q.front();
      q.pop();
      v++;
      for(auto it : adj[x]){
          indegree[it]--;
           if(indegree[it]==0){q.push(it);}
      }
     }
     if(v<N){return false;}
      return true;
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
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends