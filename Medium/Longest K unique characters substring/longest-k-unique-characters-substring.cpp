//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    unordered_map<char,int> map;
    int maxl=-1;
    int start=0;
    for(int i=0;i<s.length();i++){
     map[s[i]]++;
     if(map.size()==k){
         maxl=max(maxl,i-start+1);}
     if(map.size()>k){
         while(map.size() !=k){
         map[s[start]]-=1;
         
         if(map[s[start]]==0){map.erase(s[start]);}
         start++;
            }
          
       }
     
    }
    return maxl;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends