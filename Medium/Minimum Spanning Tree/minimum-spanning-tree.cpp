//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    { priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      int visited[V];
      memset(visited,-1,sizeof(visited));
      int min_wt=0;
      pq.push({0,0});
      while(!pq.empty()){
       auto it=pq.top();
       int wt=it.first;
       int node=it.second;
       pq.pop();
       if(visited[node]==-1){
           min_wt+=wt;
           visited[node]=0;
           for(auto i : adj[node]){
            pq.push({i[1],i[0]});
           }
       }
      }
       return min_wt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends