//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    long long noOfNumbers(long long n) {
    //  {2,3,5,7}
    long long int a=n/2 +n/3 +n/5 +n/7;
    long long int b=n/6+n/10+n/14+n/15+n/21+n/35;
    long long int c=n/30+n/70+n/105+n/42;
    long long int d=n/210;
    return n-a+b-c+d;
    
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.noOfNumbers(N) << endl;
    }
    return 0;
}
// } Driver Code Ends