//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int i,vector<int>&cost,int n,int total,vector<vector<int>>& dp){
        
        if(total==0 || i==n){return 0;}
        if(dp[i][total] !=-1){return dp[i][total];}
        int take=0;
        if(total>=cost[i]){
            take=1+solve(i+1,cost,n,total-cost[i]+floor(0.9*cost[i]),dp);
        }
        int nottake=solve(i+1,cost,n,total,dp);
        return dp[i][total]=max(take,nottake);
    }
    int max_courses(int n, int total, vector<int> &cost)
    { vector<vector<int>> dp(n+1,vector<int>(total+1,-1));
      return solve(0,cost,n,total,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends