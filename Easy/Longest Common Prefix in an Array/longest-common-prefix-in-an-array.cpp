//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
     string lcp=arr[0];
     int len=arr[0].length();
     
     for(int i=1;i<N;i++){
        if(arr[i].length()<len){
            len=arr[i].length();
            lcp=arr[i];
        }
     }
     
     for(int i=0;i<N;i++){
         int j=0;
         while(j<len){
            if(arr[i][j] !=lcp[j]){ break; }
            j++;
         }
         if(j==0){return "-1";}
         if(j !=len){
             lcp=lcp.substr(0,j);
             len=j;
         }
     }
     
     
     
     return lcp;
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
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends