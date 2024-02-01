//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
     vector<int>lowercase(26,0);
     vector<int>uppercase(26,0);
     for(char c : s){
         if( 97<= c && c<=122 ){ lowercase[c-'a']=1; }
         else if ( 65<=c && c<=90 ) { uppercase[c-'A']=1; } 
     }
     for(int i=0 ; i<26 ;i++){
         if(lowercase[i]==0 && uppercase[i]==0){return false;}
     }
     
     return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends