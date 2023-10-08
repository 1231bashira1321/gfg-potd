//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:

	int maxProduct(int arr[], int n) {
	 int max1=-1;
	 int max2=-1;
	 for(int i=0;i<n;i++){
	     if(arr[i]>max1){
	         max2=max1;
	         max1=arr[i];
	     }
	     else if(arr[i]>max2){max2=arr[i];}
	 }
	 return max1*max2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends