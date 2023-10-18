//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool dfs(int sv,int V,vector<int> adj[],vector<int> &visited){
     visited[sv]=1;
     bool flag=true;
     for(auto it : adj[sv]){
         if(!visited[it]){
          if (!dfs(it,V,adj,visited)){flag=false; break;}}
          
         else{return false;}
     }
     visited[sv]=0;
     return flag;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
     vector<int> ans;
     vector<int> visited(V,0);
     for(int i=0;i<V;i++){
         if(!visited[i]){
             if(dfs(i,V,adj,visited)){ans.push_back(i);}
         }
     }
     return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends