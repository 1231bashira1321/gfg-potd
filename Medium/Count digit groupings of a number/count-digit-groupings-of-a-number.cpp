//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int i,int prev,string& s,vector<vector<int>>&dp){
	    if(i==s.length()){return 1;}
	    if(dp[i][prev] !=-1){return dp[i][prev];}
	    int num=0;
	    int n=s.length();
	    int ans=0;
	    for(int j=i;j<n;j++){
	        num+=int(s[j]-'0');
	        if(prev<=num){
	            ans+=solve(j+1,num,s,dp);
	        }
	    }
	    return dp[i][prev]=ans;
	}
	int TotalCount(string str){
	 int n=str.length();
	 vector<vector<int>>dp(n+1,vector<int>(900+1,-1));
	 return solve(0,0,str,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends