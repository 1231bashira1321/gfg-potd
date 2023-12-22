//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{   if(a.first.second==b.first.second){return a.first.first<b.first.first;}
    return a.first.second<b.first.second;
}
 
class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
     vector<int>ans;
     vector< pair<pair<int,int>,int> > arr;
     for(int i=0;i<N;i++){
         arr.push_back( {{S[i],F[i]},i+1});}
         
     sort(arr.begin(),arr.end(),cmp);
     int prevF=-1;
     for(int i=0;i<N;i++){
         if(prevF<arr[i].first.first){
             ans.push_back(arr[i].second);
             prevF=arr[i].first.second;
         }
     }
     sort(ans.begin(),ans.end());
     return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends