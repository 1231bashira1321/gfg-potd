//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{ vector<int> visited(V,0);
	  visited[0]=1;
	  queue<int> q;
	  q.push(0);
	  int level=-1;
	  while (!q.empty()){
	      level++;
	      int len=q.size();
	      while(len--){
	       int node=q.front();
	       if(node==X){return level;}
	       q.pop();
	       for(auto it : adj[node]){
	           if(!visited[it]){
	               visited[it]=1;
	               q.push(it);}
	       }
	    }
	  }
	  return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends