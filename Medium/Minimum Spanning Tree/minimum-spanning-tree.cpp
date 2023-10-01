//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{   int get_parent(int x,int parent[]){
	  if (parent[x]==x){return x;}
	  else{
	      parent[x]=get_parent(parent[x],parent);
	      return parent[x];
	  }
	}
	
	void Union(int p1,int p2,int rank[],int parent[]){
	  if (rank[p1]>rank[p2]){
	      parent[p2]=p1;
	  }
	  else if(rank[p2]>rank[p1]){
	      parent[p1]=p2;
	  }
	  else{
	      parent[p1]=p2;
	      rank[p2]++;
	  }
	}
	
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
     int* parent=new int[V];
     int* rank=new int[V];
      for(int i=0;i<V;i++){
          rank[i]=0;
          parent[i]=i;}
      vector<pair<int,pair<int,int>>> edges;
      for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            int u=i;
            int v=adj[i][j][0];
            int wt=adj[i][j][1];
            edges.push_back({wt,{u,v}});
        }
      }
     sort(edges.begin(),edges.end());
     int index=0;
     int mst_wt=0;
     while(index !=edges.size()){
        int wt=edges[index].first;
        int u=edges[index].second.first;
        int v=edges[index].second.second;
        int pu=get_parent(u,parent);
        int pv=get_parent(v,parent);
        if(pu !=pv){
         mst_wt+=wt;
         Union(pu,pv,rank,parent);
        }
        // if(pu !=pv){
        //  mst_wt+=wt;
        //  if (rank[pu]==rank[pv]){
        //      parent[pv]==pu;
        //      pu++;}
        //  else if(rank[pu]>rank[pv]){
        //      parent[pv]=pu;}
        //  else{parent[pu]=pv;}
        // }
        index++;}
        
    //  deallocation
     delete []parent;
     delete []rank;
     return mst_wt;
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