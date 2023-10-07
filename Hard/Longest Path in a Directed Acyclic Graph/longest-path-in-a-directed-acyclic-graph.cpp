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
    
      void dfs(int sv,vector<vector<int>> adj[],int visited[],stack<int> &st){
       visited[sv]=1;
       for(auto it : adj[sv]){
           if(!visited[it[0]])
            {dfs(it[0],adj,visited,st);}
       }
       st.push(sv);
      }
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      { //make adj list
        vector<vector<int>>* adj=adj_list(v,edges);
        //create toposort
        stack<int> st;
        int visited[v]={0};
        for(int i=0;i<v;i++){
          if(!visited[i]){dfs(i,adj,visited,st);}}
        vector<int> dist(v,INT_MIN);
        dist[src]=0;
        while(!st.empty()){
            int vertex=st.top();
            st.pop();
            if(dist[vertex]==INT_MIN){continue;}
            for(auto it : adj[vertex]){
                int neighbour=it[0];
                int wt=it[1];
                if(dist[neighbour]<dist[vertex]+wt){
                    dist[neighbour]=dist[vertex]+wt;
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