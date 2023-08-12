//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solve(vector<vector<int>>& grid,int r,int c,vector<vector<int>> &dp){
        if(r<0 || c<0 || grid[r][c]==0){return 0;}
        if(r==0 && c==0)
        {return 1;}
        if(dp[r][c]==-1){
        int left=solve(grid,r,c-1,dp);
        int up=solve(grid,r-1,c,dp);
        dp[r][c]=(left+up)%(1000000007);}
        return dp[r][c];
    }
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
      vector<vector<int>> dp(n,vector<int>(m,-1));
      return solve(grid,n-1,m-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends