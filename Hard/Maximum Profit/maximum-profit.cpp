//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int solve(int A[],int i,int n,int k,int buy,vector<vector<vector<int>>> &dp){
        if(k==0){return 0;}
        if(i==n){return 0;}
        if(dp[i][k][buy] !=-1){return dp[i][k][buy];}
        int ans=0;
        if(buy){
            ans=max(-A[i]+solve(A,i+1,n,k,0,dp),solve(A,i+1,n,k,1,dp));
        }
        else{
            ans=max(A[i]+solve(A,i+1,n,k-1,1,dp),solve(A,i+1,n,k,0,dp));
        }
        dp[i][k][buy]=ans;
        return dp[i][k][buy];
        
    }
  public:
    int maxProfit(int K, int N, int A[]) {
     vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(K+1,vector<int>(2+1,-1)));
     return solve(A,0,N,K,1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends