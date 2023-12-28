//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    bool func(int i,int j,string wild,string pattern){
        if(i==wild.length() && j==pattern.length()){return true;}
        if(i==wild.length() || j==pattern.length()){return false;}
        if( (wild[i]==pattern[j]) || (wild[i]=='?') ){
            return func(i+1,j+1,wild,pattern);
        }
        if(wild[i]=='*'){
        for(int k=j;k<=pattern.length();k++){
            if(func(i+1,k,wild,pattern)){return true;}
        }}
        return false;
    }
    public:
    bool match(string wild, string pattern)
    {
        return func(0,0,wild,pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends