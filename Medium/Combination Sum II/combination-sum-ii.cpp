//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
        void solve(int i,vector<int>& arr,int target,set<vector<int>>& st,vector<int>&curr){
        if(target==0){
            if(st.find(curr)==st.end()){
            st.insert(curr);}
            return ; }
        

        if(i==arr.size()){ return ; }
      
        if(target>=arr[i]){
            curr.push_back(arr[i]);
            solve(i+1,arr,target-arr[i],st,curr);
            curr.pop_back();
        }

        solve(i+1,arr,target,st,curr);
        return ;        
    }
    
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        set<vector<int>> st;
        vector<int> curr;
        sort(arr.begin(),arr.end());
        solve(0,arr,k,st,curr);
        vector<vector<int>> ans(st.begin(),st.end());
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends