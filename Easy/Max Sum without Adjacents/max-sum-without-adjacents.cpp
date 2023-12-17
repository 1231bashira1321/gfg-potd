//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    int f(int *arr,int n,int take,vector<vector<int>> &dp){
        if(n<0){return 0;}
        if(dp[n][take] !=-1){return dp[n][take];}
        int taken=0;
        if(take){
         taken=arr[n]+f(arr,n-1,0,dp);
        }
        int nottaken=f(arr,n-1,1,dp);
        dp[n][take]=max(taken,nottaken);
        return dp[n][take];
    }
public:	

	int findMaxSum(int *arr, int n) {
	 vector<vector<int>> dp(n+1,vector<int>(2,-1));
	 return f(arr,n-1,1,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends