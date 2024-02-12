//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    long long mod=1e9+7;
    long long solve(long long start,int times,int n){
        if(times>n){ return 0; }
        long long curr=1;
        for(int i=0;i<times;i++){
            curr=curr*start%mod;
            start++;
        }
        return ((curr %mod) + (solve(start,times+1,n)%mod))%mod ;
    }
public:
    long long sequence(int n){
     return solve(1,1,n) ;
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
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends