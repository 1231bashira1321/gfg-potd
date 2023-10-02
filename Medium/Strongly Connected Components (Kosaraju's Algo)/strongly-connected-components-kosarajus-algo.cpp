//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    void dfs2(int node,vector<vector<int>>& adj,int visited[]){
    visited[node]=1;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs2(neighbour,adj,visited);}
    }
}
    
    
    
    void dfs(int node,vector<vector<int>>& adj,int visited[],stack<int> &st){
    visited[node]=1;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,adj,visited,st);}
    }
    st.push(node);
}


	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {int visited[V]={0};
     stack<int> st;
     for(int i=0;i<V;i++){
         if(!visited[i]){dfs(i,adj,visited,st);}
     }
     
     //reverse graph
     vector<vector<int>> adjrev(V);
    for(int i=0;i<V;i++){
        for(auto j : adj[i]){
            adjrev[j].push_back(i);
        }
    }
     
     memset(visited,0,sizeof(visited));
     int scc=0;
     while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            scc++;
            dfs2(node,adjrev,visited);}
     }
     return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends