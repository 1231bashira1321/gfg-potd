//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs(int N,int M, vector<vector<int>>& edges,vector<int> &visited,stack<int> &st){
        visited[N]=1;
        for(auto it : edges){
            if(it[0]==N && !visited[it[1]]){
                dfs(it[1],M,edges,visited,st);
            }
        }
        st.push(N);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
     //create toposort
     stack<int> st;
     vector<int> visited(N,0);
     //for disconnected graph
     for(int i=0;i<N;i++){
         if(!visited[i]){
      dfs(i,M,edges,visited,st);}   
     }
     vector<int> dist(N,1e9);
     dist[0]=0;
     while (!st.empty()){
         int node=st.top();
         st.pop();
         for(auto it : edges){
            if(it[0]==node && dist[it[1]]>dist[node]+it[2]){
               dist[it[1]]=dist[node]+it[2];
            }
        }
     }
     
     for(int i=0;i<N;i++){
         if(dist[i]==1e9){dist[i]=-1;}}
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