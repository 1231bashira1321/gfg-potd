//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{int mod=1000000007;
	 int prev_end_with_S=1;
	 int prev_end_with_B=1;
	 for(int i=1;i<N;i++){
	   int prevS=prev_end_with_S%(mod);
	   prev_end_with_S=(prev_end_with_S %(mod) + prev_end_with_B %(mod) ) %(mod);
	   prev_end_with_B=prevS;
	 }
	 int total=(prev_end_with_S %(mod)+prev_end_with_B %(mod)) %(mod);
	 int ans=static_cast<int>( (1LL*total*total)%(mod) );
	 return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends