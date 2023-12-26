//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int dijkstra(int V, vector<vector<pair<int,int>>> adj, int S,int distanceThreshold)
    {priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
     vector<int> dist(V,1e9);
     dist[S]=0;
     pq.push({dist[S],S}); // dist,node
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
     int ans=0;
     for(int i=0;i<V;i++){
         if(dist[i]<=distanceThreshold){ans++;}
     }
     return ans;
    }
    
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
         vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
          int u=edges[i][0];
          int v=edges[i][1];
          int wt=edges[i][2];
          adj[u].push_back({v,wt});
          adj[v].push_back({u,wt});}
        
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
         arr[i]=dijkstra(n,adj,i,distanceThreshold);}
         
        int ans=0;
        int numCities=109;
        for(int i=0;i<n;i++){
         if(numCities>=arr[i]){
             ans=i;
             numCities=arr[i];}
        }
        return  ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends