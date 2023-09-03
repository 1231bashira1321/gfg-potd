//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{   int solve(vector<vector<int>>&dp,int m,int n){
        if(n<0 || m<0){return 0;}
        if(m==0 && n==0){return 1;}
        if(dp[m][n] !=-1){return dp[m][n];}
        return dp[m][n]=solve(dp,m,n-1)+solve(dp,m-1,n);
    }
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
     vector<vector<int>> dp(a,vector<int>(b,-1));
     return solve(dp,a-1,b-1);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends