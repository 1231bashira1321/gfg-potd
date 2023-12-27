//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
     vector<int> dis(N,1e8);
     dis[0]=0;
	 for(int i=0;i<N;i++){
	  for(auto it: edges){
	      int u=it[0];
	      int v=it[1];
	      int wt=it[2];
	      if(dis[v]>dis[u]+wt){
	       dis[v]=dis[u]+wt;  
	      }
	  }
	 }
	 for(int i=0;i<N;i++){
	     if(dis[i]==1e8){dis[i]=-1;}
	 }
	 return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends