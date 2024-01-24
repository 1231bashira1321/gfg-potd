//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int nums[], int low, int high)
    { if(low>high){return 1e9;}
      int mid=(low+high)/2;
      
      if(nums[mid]>nums[high]){
        return min(nums[mid],minNumber(nums,mid+1,high));}
      
      return min(nums[mid],minNumber(nums,low,mid-1));
        
    }
};

//{ Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends