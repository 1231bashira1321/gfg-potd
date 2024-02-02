//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
     
     int num=0;
     int n=s.length();
     bool neg=false;
     
     for(int i=0;i<n;i++){
         
         int digit=s[i]-'0';
         
         if(i==0 && s[0]=='-'){
             neg=true;
         }
         
         else if( 0<= digit && digit <=9 ){
          
          num=num + digit*pow(10,n-i-1);
         }
         
         else { return -1; }
     }
     if(neg){ return -1*num;}
     return num;
     
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends