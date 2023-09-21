//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int FindMaxSum(int arr[], int n){
    // {vector<int> dp(n+1,0);
    //  dp[0]=arr[0];
     int prev=0;          //stands for i-2
     int curr=arr[0];    //stands for i-1
     for(int i=1;i<n;i++){
         int nottake=curr;
         int take=arr[i];
         if (i>=2){
          take+=prev;}
         prev=curr;
         curr=max(take,nottake);
     }
     return curr;
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends