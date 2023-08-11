//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
     vector<vector<long long int>> dp(N,vector<long long int>(sum+1,0));
     
     for(int i=0;i<N;i++){
         for(int target=0;target<=sum;target++){
            if(target==0) {dp[i][target]=1;}
            else if (i==0){
                if(target%coins[0]==0){dp[i][target]=1;}
            }
            else{
             long long int take=0;
             if (coins[i]<=target){
              take=dp[i][target-coins[i]];}
             long long int nottake=dp[i-1][target];
             dp[i][target]=take+nottake;}
         }
     }
     return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends