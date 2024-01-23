//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
      void solve(int i,int k,int target,vector<int>&path,vector<vector<int>>&ans){
        if(target==0 && k==0){
            ans.push_back(path);
            return;}
  
        for(int j=i;j<=9;j++){
            path.push_back(j);
            solve(j+1,k-1,target-j,path,ans);
            path.pop_back();
        }
        return;
    }
  public:
    vector<vector<int>> combinationSum(int K, int N) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(1,K,N,path,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends