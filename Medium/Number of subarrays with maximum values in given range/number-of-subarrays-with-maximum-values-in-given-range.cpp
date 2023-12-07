//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
         int start = -1;
        int end = -1;
        
        long count = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > R) {
                start = i;
                end = i;
                continue;
            }
            
            if(a[i] >= L) {
                end = i;
            }
            
            count += (end - start);
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends