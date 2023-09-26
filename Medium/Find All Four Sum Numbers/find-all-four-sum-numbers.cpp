//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
     vector<vector<int>> v;
     int n=arr.size();
     sort(arr.begin(),arr.end());
     for(int i=0;i<n-2;i++){
         if (i !=0 && arr[i]==arr[i-1]){continue;}
         for(int j=i+1;j<n-1;j++){
             if(j !=i+1 && arr[j]==arr[j-1]){continue;}
             int p=j+1;
             int q=n-1;
             while(p<q){
                 int sum=arr[i]+arr[j]+arr[p]+arr[q];
                 if(sum==k){
                     vector<int> vin={arr[i],arr[j],arr[p],arr[q]};
                     v.push_back(vin);
                     p+=1;
                     q-=1;
                     while(p<q && arr[p] == arr[p-1]) p++;
                     while(p<q && arr[q] == arr[q+1]) q--;
                 }
                  else if (sum >k){
                      q--;
                  }
                  else{
                      p++;
                  }}}}
     return v;}
};
     
     


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends