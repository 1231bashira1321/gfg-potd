//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
     vector<int> ans;
     priority_queue<pair<int,int>> heap;
     for(int i=0;i<k;i++){
         heap.push({arr[i],i});
     }
     ans.push_back(heap.top().first);
     for(int i=k;i<n;i++){
         //remove elements from previous window
         while(!heap.empty() && heap.top().second<=i-k){
             heap.pop();
         }
         heap.push({arr[i],i});
         ans.push_back(heap.top().first);
     }
     return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends