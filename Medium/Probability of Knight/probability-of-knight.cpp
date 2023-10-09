//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    double solve(int r,int c,int steps,int N,vector<vector<vector<double>>>& dp){
     if(steps==0){return 1.0;}
     if(dp[r][c][steps] !=-1.0){return dp[r][c][steps];}
     int dx[]={1,1,-1,-1,2,2,-2,-2};
	 int dy[]={2,-2,2,-2,1,-1,1,-1};
	 double ans=0.0;
	 for(int i=0;i<8;i++){
	     int new_row=r+dx[i];
	     int new_col=c+dy[i];
	     if(new_row>=0 && new_row<N && new_col>=0 && new_col<N){
	         ans+= solve(new_row,new_col,steps-1,N,dp)/8;
	     }
	 }
	dp[r][c][steps]=ans;
    return ans;
        
    }
     
	public:
	double findProb(int N,int start_x, int start_y, int steps)
	{vector<vector<vector<double>>> dp(N,vector<vector<double>>(N,vector<double>(steps+1,-1.0)));
	 return solve(start_x,start_y,steps,N,dp);
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends