//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum)
    {
     int curr_sum = 0,count=0;
     unordered_map<int,int> map;
     for (int i = 0; i < n; i++) {
        curr_sum = curr_sum + arr[i];
        if (curr_sum == sum) {
           count++;
        }
        if (map.find(curr_sum - sum) != map.end()) {
           count+=map[curr_sum-sum];
        }
        map[curr_sum]++;
     }
     return count;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution obj;
	    cout<<obj.subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}
// } Driver Code Ends