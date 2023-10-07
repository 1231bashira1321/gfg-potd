//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{     vector<vector<int>>* adj_list(int v,vector<vector<int>> edges){
        vector<vector<int>>* adj=new vector<vector<int>>[v];
        for(auto it : edges){
            vector<int> v={it[1],it[2]};
            adj[it[0]].push_back(v);
        }
        return adj;
      }
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      { //make adj list
        vector<vector<int>>* adj=adj_list(v,edges);
        vector<int> dist(v,INT_MIN);
        dist[src]=0;
        priority_queue<pair<int,int>> pq;
        pq.push({src,dist[src]});
        while(!pq.empty()){
            int vertex=pq.top().first;
            int d=pq.top().second;
            pq.pop();
            for(auto it : adj[vertex]){
                int neighbour=it[0];
                int wt=it[1];
                if(dist[neighbour]<d+wt){
                    dist[neighbour]=d+wt;
                    pq.push({neighbour,dist[neighbour]});
                }
            }
        }
        
        delete[] adj;
        return dist;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends