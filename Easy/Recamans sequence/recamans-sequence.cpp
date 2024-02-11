//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
     
     unordered_map<int,int>vis;
     vis[0]=1;
     vector<int>ans(n,0);
     
     for(int i=1;i<n;i++){
         int curr=ans[i-1]-i;
         if(curr<0 || vis[curr]==1){
             curr=ans[i-1]+i;
         }
         vis[curr]=1;
         ans[i]=curr;
     }
     
     return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends