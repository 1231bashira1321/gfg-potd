//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPointutil(int n,vector<int> &dp){
		 if(n<=0){return n==0;}
		 else if (dp[n] !=-1){return dp[n];}
		 dp[n]=(nthPointutil(n-1,dp)+nthPointutil(n-2,dp) )%1000000007;
		 return dp[n];
		}
	   int nthPoint(int n){
		 vector<int> dp(n+1,-1);
		 return nthPointutil(n,dp);
	       
	   }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends