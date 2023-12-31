//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int solve(int coins[],int n,int target){
        if(target !=0 && (!(target% 20) || !(target% 24) || target==2024)){return 1;}
        if(n<0){return 0;}
        int take=solve(coins,n-1,target+coins[n]);
        if (take==1){
            return 1;
        }
        return solve(coins,n-1,target);
    }
    public:
    int isPossible(int N , int coins[]) 
    {
        return solve(coins,N-1,0);
        
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends