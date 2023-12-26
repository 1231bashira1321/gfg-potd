//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
      vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<edges.size();i++){
          int u=edges[i][0];
          int v=edges[i][1];
          int wt=edges[i][2];
          adj[u].push_back({v,wt});
        }
     priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
     vector<int> dist(N,1e9);
     dist[0]=0;
     pq.push({dist[0],0}); // dist,node
     while(!pq.empty()){
         int d=pq.top().first;
         int s=pq.top().second;
         pq.pop();
         for(auto it : adj[s]){
             int v=it.first;
             int wt=it.second;
             if(dist[v] >wt+d){
                 dist[v]=wt+d;
                 pq.push({dist[v],v});
             }
             
         }
        
     }
     for(int i=0;i<N;i++){
         if(dist[i]==1e9){dist[i]=-1;}
     }
     return dist;
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