//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
     int n=nums.size();
     if(n % 2){return false;}
     unordered_map<int,int> mp;
     for(int i=0;i<n;i++){
       int Remainder=nums[i]%k;
         
       if(Remainder==0){continue;}
         
       else if(mp.count(k-Remainder)){
           mp[k-Remainder]--;
           if(mp[k-Remainder]==0){mp.erase(k-Remainder);}
       }
       
       else {
           mp[Remainder]++;
       }
     }
     if(mp.empty()){return true;}
     return false;
   
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends