//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	   int odd=0;//set bits at odd position
	   int even=0;//set bits at even position
	   for(int i=s.length()-1;i>=0;i--){
	       if(s[i]=='1'){
	         if(i & 1){ odd++; }
	         else{ even++; }
	       }
	   }
	   int count=abs(even-odd);
	   return count%3==0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends