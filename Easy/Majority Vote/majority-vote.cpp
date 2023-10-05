//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   /*eg-consider n=8;
    we need to find elements greater than n/3 that is 8/3(2.6)
    means we need to pick elements that at least appear 3 times.
    if there exists 3 elements which appear 3 times n will be 9 as
    3+3+3=9 which will be wrong as n is 8 .so we can at max have 2 majority elements 
    
    */
    vector<int> Solve(int n, vector<int>& nums) {
     vector<int> ans;
     int cnt1=0;
     int cnt2=0;
     int ele1=0;
     int ele2=0;
     for(int i=0;i<n;i++){
         if(cnt1==0 && ele2 !=nums[i]){
             cnt1++;
             ele1=nums[i];
         }
         else if(cnt2==0 && ele1 !=nums[i]){
             cnt2++;
             ele2=nums[i];
         }
         else if(ele1==nums[i]){cnt1++;}
         else if(ele2==nums[i]){cnt2++;}
         else {cnt1--;cnt2--;}
     }
     //check
     cnt1=0;
     cnt2=0;
     for(int i=0;i<n;i++){
         if(ele1==nums[i]){cnt1++;}
         else if(ele2==nums[i]){cnt2++;}
     }
     int mini=(int)(n/3) +1;
     if(cnt1>=mini){ans.push_back(ele1);}
     if(cnt2>=mini){ans.push_back(ele2);}
     if(ans.empty()){ans.push_back(-1);}
     return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends