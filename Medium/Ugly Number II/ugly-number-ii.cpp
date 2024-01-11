//{ Driver Code Starts
//Initial Template for C++

// {Driver code starts
#include<bits/stdc++.h>
using namespace std;

//}Driver code ends


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int uglyNumber(int n)
    {
        vector<int> dp(n,0);
        dp[0]=1;
        int p2=0;
        int p3=0;
        int p5=0;
        for(int i=1;i<n;i++){
            int twoMultiple=dp[p2]*2;
            int threeMultiple=dp[p3]*3;
            int fiveMultiple=dp[p5]*5;
            dp[i]=min({ twoMultiple, threeMultiple, fiveMultiple });

            if(dp[i]==twoMultiple){p2++;}
            if(dp[i]==threeMultiple){p3++;}
            if(dp[i]==fiveMultiple){p5++;}
           
            
        }
        return dp[n-1];
    }
    
};



//{ Driver Code Starts.

//{Driver code starts
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        int res;
        res=ob.uglyNumber(n);
        
        cout<<res;
        cout<<"\n";    
    }
}



// } Driver Code Ends