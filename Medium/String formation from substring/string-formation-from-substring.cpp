//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    int n=s.length();
	    for(int i=n/2 ; i>=1 ; i--){
	        
	        if(n%i==0){ //substr lenght (i) should be multiple of s length
	             string pattern=s.substr(0,i);
	             int times=n/i;
	             string ns="";
	             while(times--){
	                 ns+=pattern;
	             }
	             if(ns==s){return true;}
	            
	            
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}
// } Driver Code Ends