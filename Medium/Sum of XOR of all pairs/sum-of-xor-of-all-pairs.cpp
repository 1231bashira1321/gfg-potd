//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
        long long int result = 0;


        for (int i = 0; i < 32; i++)
        {
            long set_bits = 0;
            long unset_bits = 0;
            
            long long int bit_checker = 1 << i;
            
            for (int idx = 0; idx < n; idx++)
            {
                if ((arr[idx] & bit_checker) == 0)
                {
                    unset_bits++;
                }
                else
                {
                    set_bits++;
                }
            }
            
            long long int total_xors = set_bits * unset_bits;
            
            long long int bit_sum = total_xors * bit_checker;
            
            result += bit_sum;
            
            
        }
        
        return result;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends