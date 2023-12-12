//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   void Union(int pu,int pv,vector<int> & rank,vector<int> &parent){
    if(rank[pu]>rank[pv]){
        parent[pv]=pu;}
    else if(rank[pu]<rank[pv]){
        parent[pu]=pv;}
    else{parent[pu]=pv;
         rank[pv]++;}}
         
    int get_parent(int x,vector<int> &parent){
        if(parent[x]==x){return x;}
        parent[x]=get_parent(parent[x],parent);
        return parent[x];
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
     vector<pair<int,pair<int,int>>> edges;
     for (int i=0;i<V;i++){
         for(auto neigh : adj[i]){
             edges.push_back({neigh[1],{i,neigh[0]}});
         }
     }
     
     vector<int> parent(V);
     for(int i=0;i<V;i++){parent[i]=i;}
     vector<int> rank(V,0);
     
     sort(edges.begin(),edges.end());
     int mst=0;
     for(int i=0;i<edges.size();i++){
       int wt=edges[i].first;
       int u=edges[i].second.first;
       int v=edges[i].second.second;
       int pu=get_parent(u,parent);
       int pv=get_parent(v,parent);
       //discard the edge if form cycle
       if(pu!=pv){
        mst+=wt;
        Union(pu,pv,rank,parent);}
     }
     return mst;
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