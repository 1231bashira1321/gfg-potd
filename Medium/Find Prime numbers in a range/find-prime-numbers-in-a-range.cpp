//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
     if(M>N){return primeRange(N,M);}
     vector<bool> prime(N+1,true);
     prime[0]=false;
     prime[1]=false;
     vector<int> ans;
     for(int i=2 ;i<=N ;i++){
         if(prime[i]==true){ //if marked false then all its multiple is also marked and it is not a prime factor
          for(long long int j=1LL*i*i ; j<=N;j+=i){ //as marking multiples of i so jump through i
           prime[j]=false; //not a prime number
          }
         }
     }
     
     
     for(int i=M;i<=N;i++){
         if(prime[i]){
             ans.push_back(i);
         }
     }
     return ans;
     
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends