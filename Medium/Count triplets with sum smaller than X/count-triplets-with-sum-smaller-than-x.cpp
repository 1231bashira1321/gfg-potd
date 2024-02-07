//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{long long int count=0;
	 sort(arr,arr+n);
	 for(int i=0;i<=n-3;i++){
	    int low=i+1;
	    int high=n-1;
	    long long int s=arr[i];
	    while(low<high){
	   
	      if( (s+arr[low]+arr[high])<sum){
	          count+=(high-low);
	          low++;}
	      else { high--; }
	      
	    }
	   
	 }
	 return count;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends