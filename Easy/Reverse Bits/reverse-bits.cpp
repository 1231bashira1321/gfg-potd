//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
     string ans="";
     while(n !=0){
         if(n & 1){ans.push_back('1');}
         else{ans.push_back('0');}
         n>>=1;
     }
    
    unsigned int result=0;
    int c=0;
    while(ans.length() !=0){
        if(ans[ans.length()-1]=='1'){result+=1<<c;}
        c++;
        ans.pop_back();
    }
    return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout<< ob.reverseBits(N) <<"\n";
        
    }
    return 0;
}

// } Driver Code Ends