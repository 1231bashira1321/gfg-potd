//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long solve(int r,int c,vector<vector<int>>&arr,int k,int n,vector<vector<vector<long long>>>&dp){
        if(k==arr[r][c] && r==n-1 && c==n-1){ return 1; } 
        if(k<=0 || r==n || c==n){ return 0; }
        if(dp[r][c][k] !=-1){ return dp[r][c][k]; }
        return dp[r][c][k]=solve(r+1,c,arr,k-arr[r][c],n,dp)+solve(r,c+1,arr,k-arr[r][c],n,dp);
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
     vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(n+1,vector<long long>(k+1,-1)));
     return solve(0,0,arr,k,n,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends