//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
       //we need to find shortest path within k stops so using dijikstra algorithm
       //putting this in priority queue {dist,node,stops} will give wrong ans
       //so putting this {stops,node,dist}
       //but we know after every iteration stops increases by 1 so increase is constant
       //thats why using queue
        vector<vector<int>>* make_adj(int v,vector<vector<int>>& edges){
        vector<vector<int>>* adj=new vector<vector<int>>[v];
        for(auto it : edges){
         vector<int> vec={it[1],it[2]};
         adj[it[0]].push_back(vec);
        }
        return adj;
    }
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
      vector<vector<int>>* adj=make_adj(n,flights);
      vector<int> dist(n,1e9);
      dist[src]=0;
      queue<pair<int,pair<int,int>>> q;
      q.push({0,{src,0}});
      while(!q.empty()){
         int stops=q.front().first;
         int node=q.front().second.first;
         int distance=q.front().second.second;
         q.pop();
         if(stops>K){continue;}
            for(auto it :adj[node]){
                int neigh=it[0];
                int wt=it[1];
                if(dist[neigh]>distance+wt && stops<=K){
                    dist[neigh]=distance+wt;
                    q.push({stops+1,{neigh,dist[neigh]}});
                }
            }
         
      }
      delete[] adj;
      if(dist[dst]==1e9){return -1;}
      return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends