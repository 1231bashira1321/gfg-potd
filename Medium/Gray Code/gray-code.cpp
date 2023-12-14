//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> graycode(int n)
    {
     /*
     n=1 {0,1} //base case
     n=2 attach zeroes to all elements of above array then reverse the above array then attach 1 to elements
         {00,01,11,10}
     n=3 {000,001,011,010,110,011,101,100}
     */
     if(n==1)return {"0","1"};
     vector<string> arr=graycode(n-1);
     vector<string> ans;
     int len=arr.size();
     for(int i=0;i<len;i++){
         ans.push_back('0'+arr[i]);}
     for(int i=0;i<len;i++){
         ans.push_back('1'+arr[len-1-i]);}
     return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}




// } Driver Code Ends