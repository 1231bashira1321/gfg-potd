//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void solve(vector<vector<int>>&matrix,vector<vector<int>>&vis,int r,int c,int xd,int yd,int &ans,int path){
        if(r==matrix.size() || c==matrix[0].size() || r<0 || c<0 || matrix[r][c]==0 || vis[r][c]==1){return ;}
        if(r==xd && c==yd){
            ans=max(ans,path);
            return ;}
        
        vis[r][c]=1;
       
        solve(matrix,vis,r,c-1,xd,yd,ans,path+1);
        solve(matrix,vis,r-1,c,xd,yd,ans,path+1);
        solve(matrix,vis,r,c+1,xd,yd,ans,path+1);
        solve(matrix,vis,r+1,c,xd,yd,ans,path+1);
        vis[r][c]=0;
        return;
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {   int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        int ans=-1;
        solve(matrix,vis,xs,ys,xd,yd,ans,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends