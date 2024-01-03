//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
     
     int n=s.length();
     int window=n+1;
     int count[]={0,0,0};
     int end=0;
     int start=0;
     while(end<n){
         count[s[end]-'0']++;
         
         if(count[0]>0 && count[1]>0 && count[2]>0){
             window=min(window,end-start+1);
             count[s[start]-'0']--;
             start++;
             count[s[end]-'0']--;
         
         } else {
             end++;
         }
     }
      if(count[0]>0 && count[1]>0 && count[2]>0){
             window=min(window,end-start);}
     return window==n+1? -1 : window;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends