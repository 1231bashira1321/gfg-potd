//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
     vector<long long> ans={1};
     for(int row=1;row<n;row++){
         vector<long long> r(row+1,0);
         r[0]=ans[0];
         for(int col=1;col<=row;col++){
          if(col==row){
             r[col]=ans[col-1]%(1000000007);
          }
          else{
             r[col]=(ans[col-1]+ans[col])%(1000000007);  
          }
         }
         ans=r;
     }
     return ans;
    }
};



//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends