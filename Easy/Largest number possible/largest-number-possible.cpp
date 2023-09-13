//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
       if (S == 0 && N > 1) {
    return "-1";
  }

  if (S > 9 * N) {
    return "-1";
  }

  
  string largestNumber = "";

  
  for (int i = N - 1; i >= 0; i--) {
    
    int largestDigit = 9;
    if (S >= 9) {
      largestDigit = 9;
    } else {
      largestDigit = S;
    }

    
    largestNumber += to_string(largestDigit);
    S -= largestDigit;
  }

  return largestNumber;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends