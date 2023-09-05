//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void dfs(vector<vector<char>> &mat,int r,int c,vector<vector<int>>&vis){
     vis[r][c]=1;
     int dx[]={-1,0,1,0};
     int dy[]={0,1,0,-1};
     int n=mat.size();
     int m=mat[0].size();
     for(int i=0;i<4;i++){
         int newr=r+dx[i];
         int newc=c+dy[i];
         if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0 && mat[newr][newc]=='O')
          {dfs(mat,newr,newc,vis);}
     }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
      //O (or set of O) connected to boundary will not be converted to X
      vector<vector<int>> vis(n,vector<int>(m,0));
      for(int i=0;i<m;i++){
          //first row
          if(mat[0][i]=='O' && vis[0][i]==0){dfs(mat,0,i,vis);}
          //last row
          if(mat[n-1][i]=='O' && vis[n-1][i]==0){dfs(mat,n-1,i,vis);}
      }
      for(int i=0;i<n;i++){
          //first col
          if(mat[i][0]=='O' && vis[i][0]==0){dfs(mat,i,0,vis);}
          //last col
          if(mat[i][m-1]=='O' && vis[i][m-1]==0){dfs(mat,i,m-1,vis);}
      }
      //convert
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(vis[i][j]==0 && mat[i][j]=='O'){mat[i][j]='X';}
          }
      }
     return mat; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends