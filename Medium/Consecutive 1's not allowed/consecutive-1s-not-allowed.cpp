//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	 ll nz=1;
	 ll no=1;
	 while(n !=1){
	     ll nnz=nz+no;
	     ll nno=nz;
	     nz=nnz%1000000007;
	     no=nno%1000000007;
	     n--;
	 }
	 return (nz+no)%1000000007;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends