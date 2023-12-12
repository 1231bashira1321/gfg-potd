//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxGolduntil(int row,int col,int n,int m,vector<vector<int>>& M,vector<vector<int>>& dp){
     if(row<0 || row==n || col==m){return 0;}
     if(dp[row][col] !=-1){return dp[row][col];}
     int updiagonal=maxGolduntil(row-1,col+1,n,m,M,dp);
     int right=maxGolduntil(row,col+1,n,m,M,dp);
     int downdiagonal=maxGolduntil(row+1,col+1,n,m,M,dp);
     int ans=M[row][col]+max(updiagonal,max(right,downdiagonal));
     dp[row][col]=ans;
     return ans;
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
     vector<vector<int>> dp(n,vector<int>(m,-1));
     int maxi=-1;
     for(int row=0;row<n;row++){
         maxi=max(maxi,maxGolduntil(row,0,n,m,M,dp));
     }
     return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends