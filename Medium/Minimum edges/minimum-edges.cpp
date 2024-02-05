//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    
    int dijkstra(int V, vector<vector<int>> adj[],int src,int dst)
    {priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
     vector<int> dist(V+1,1e9);
     dist[src]=0;
     pq.push({dist[src],src}); // dist,node
     while(!pq.empty()){
         int d=pq.top().first;
         int s=pq.top().second;
         pq.pop();
         for(auto it : adj[s]){
             int v=it[0];
             int wt=it[1];
             if(dist[v] >wt+d){
                 dist[v]=wt+d;
                 pq.push({dist[v],v});
             }
             
         }
        
     }
     return dist[dst];
    }
    
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
         vector<vector<int>> adj[n+1];
         for(auto it : edges){
             adj[it[0]].push_back({it[1],0});
             adj[it[1]].push_back({it[0],1}); //weight of the reverse edge
         }
         
         int ans=dijkstra(n,adj,src,dst);
         return ans>=1e9? -1 : ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends