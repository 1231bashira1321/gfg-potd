//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int r,int c,vector<vector<int>>& visited,vector<vector<int>>& grid,vector<pair<int,int>>& island,int base_r,int base_c){
        if(r<0 || r==grid.size() || c<0 || c==grid[0].size() || visited[r][c]==1 || grid[r][c]==0){return ;}
        visited[r][c]=1;
        island.push_back({r-base_r,c-base_c});
        dfs(r+1,c,visited,grid,island,base_r,base_c);
        dfs(r-1,c,visited,grid,island,base_r,base_c);
        dfs(r,c+1,visited,grid,island,base_r,base_c);
        dfs(r,c-1,visited,grid,island,base_r,base_c);
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
     //count all islands store in set it will give unique islands
     int R=grid.size();
     int C=grid[0].size();
     vector<vector<int>> visited(R,vector<int>(C,0));
     set<vector<pair<int,int>>> st;
     for(int i=0;i<R;i++){
         for(int j=0;j<C;j++){
             if(!visited[i][j] && grid[i][j]){
                 vector<pair<int,int>> island;
                 dfs(i,j,visited,grid,island,i,j);
                 st.insert(island);
             }
         }
     }
     return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends