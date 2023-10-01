//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    { //brute force method
      string temp;
      temp=arr[0];
      for(int i=1;i<N;i++){
       //compare strings
       int j=0;
       string s;
        for(j=0;j<min(temp.length(),arr[i].length());j++){
            if(temp[j] !=arr[i][j]){break;}
            s+=temp[j];
        }
        temp=s;
        if(j==0){return "-1";}
      }
     if (temp.size()==0){return "-1";}
     return temp;
     
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