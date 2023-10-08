//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void dfs(int r,int c,vector<vector<int>> &visited,vector<vector<char>>& grid){
     int n=grid.size();
     int m=grid[0].size();
     if(r<0 || r==n || c<0 || c==m || visited[r][c]==1 || grid[r][c]=='0'){return ;}
     int dx[]={-1,-1,0,1,1,1,0,-1};
     int dy[]={0,1,1,1,0,-1,-1,-1};
     visited[r][c]=1;
     for(int i=0;i<8;i++){
         dfs(r+dx[i],c+dy[i],visited,grid);
     }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
    //  int visited[n][m];
    //  memset(visited,0,sizeof(visited));
     int ans=0;
     vector<vector<int>> visited(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(!visited[i][j] &&  grid[i][j]=='1'){
                 ans++;
                 dfs(i,j,visited,grid);
             }
         }
     }
     return ans;
     
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends