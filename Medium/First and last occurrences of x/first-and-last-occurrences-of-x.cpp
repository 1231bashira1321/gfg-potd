//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>v;
               int i=binary_search(arr,arr+n,x);
               if(i==0)
               {
                   v.push_back(-1);
                    v.push_back(-1);
                    return v;
               }
           auto it=lower_bound(arr, arr+n, x);
                v.push_back(it-arr);
            auto it1=upper_bound(arr, arr+n, x);
                v.push_back(it1-arr-1);    
               
                return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends