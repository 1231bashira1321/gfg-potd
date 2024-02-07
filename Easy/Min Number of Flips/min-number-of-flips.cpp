//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{   //alternate string starting with 1--->count of flips--->a
    //alternate string starting with 0--->count of flips--->b
    int n=s.length();
    int a=0;
    int c=0;
    for(int i=0 ;i<n;i++){
        if((s[i]-48) !=c){ a++; }
        c=1-c;
    }
    int b=0;
    c=1;
    for(int i=0 ;i<n;i++){
        if((s[i]-48)!=c){ b++; }
        c=1-c;
    }

    return min(a,b);
}