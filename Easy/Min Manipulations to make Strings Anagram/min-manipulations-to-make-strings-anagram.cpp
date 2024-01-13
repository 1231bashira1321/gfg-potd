//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int minManipulation (int n, string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << minManipulation (n, s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minManipulation (int N, string s, string t)
{
     unordered_map<char,int> freq;
     for(int i=0;i<s.length();i++){
         freq[s[i]]++;
     }
     for(int i=0;i<t.length();i++){
         freq[t[i]]--;
     }     
     int ans=0;
     for(auto it : freq){
       if(it.second>0){
           ans+=it.second;
       }
     }
     return ans;
}