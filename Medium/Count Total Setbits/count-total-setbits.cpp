//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N){
        
     if(N==0){return 0;}
        
      int x=0; //largest power of 2
      while( (1<<x) <=N ){
          x++;
      }
      x--;
      return (1<<(x-1))*x +  N-(1<<x) + 1 +countBits(N-(1<<x));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends