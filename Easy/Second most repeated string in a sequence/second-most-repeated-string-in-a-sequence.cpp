//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
     map<string,int> mp;
     for(int i=0;i<n;i++){ mp[arr[i]]++;}
     int fmax=0;
     int smax=0;
     string fs="";
     string ss="";
     for(auto it=mp.begin();it !=mp.end();it++){
         if(it->second>fmax){
             smax=fmax;
             ss=fs;
             fmax=it->second;
             fs=it->first;
         } else if( it->second>smax){
             smax=it->second;
             ss=it->first;
         }
     }
     return ss;
     
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends