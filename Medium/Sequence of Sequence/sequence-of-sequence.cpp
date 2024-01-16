//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int n,int m,int a){
        if(a>m){return 0;}
        if(n==0){return 1;}
        int ans=0;
        for(int i=2*a;i<=m;i++){
            if(i==0){continue;}
            ans+=solve(n-1,m,i);
        }
        return ans;
    }
public:
    int numberSequence(int m, int n){
       solve(n,m,0);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends