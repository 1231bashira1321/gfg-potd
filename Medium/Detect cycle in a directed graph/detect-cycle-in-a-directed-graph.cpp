//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // bool dfs(int sv,vector<int> adj[],bool* visited,bool* recursion_stack){
    //     recursion_stack[sv]=true;
    //     visited[sv]=true;
    //     for(auto i : adj[sv]){
    //         if(!visited[i]){
    //             if(dfs(i,adj,visited,recursion_stack)){return true;};
                
    //         } else if(recursion_stack[i]==true){return true;}
    //         }
    //     recursion_stack[sv]=false;
    //     return false;
    // }
     bool dfs(int sv, vector<int> adj[], bool* visited, bool* recursion_stack) {
        recursion_stack[sv] = true;
        visited[sv] = true;
        for (auto i : adj[sv]) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recursion_stack)) {
                    return true;
                }
            } else if (recursion_stack[i] == true) { // Change = to ==
                return true;
            }
        }
        recursion_stack[sv] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
      bool visited[V]={false};
      bool recursion_stack[V]={false};
    //   memset(visited,false,sizeof(visited));
    //   memset(recursion_stack,false,sizeof(recursion_stack));
      for(int i=0;i<V;i++){
          if(!visited[i]){
              if(dfs(i,adj,visited,recursion_stack)){
                //   delete[] visited; //deallocation
                //   delete[] recursion_stack;
                  return true;
              }
          }
      }
    //   delete[] visited;
    //   delete[] recursion_stack;
      return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends