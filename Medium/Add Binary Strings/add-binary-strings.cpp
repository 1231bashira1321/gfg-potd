//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	  int l1=a.length();
      int l2=b.length();
      string ans="";
      int carry=0;
      if(l1<l2){return addBinary(b,a);}
      l1--;l2--;
      while(l1>=0 && l2>=0){
        if(a[l1]=='1' && b[l2]=='1'){
          if(carry==0){carry=1;ans.push_back('0');}
          else{ans.push_back('1');}}
        else if(a[l1]=='0' && b[l2]=='0'){
          if(carry==0){ans.push_back('0');}
          else{carry=0;ans.push_back('1');}}
        else{ if(carry==0){ans.push_back('1');}
          else{ans.push_back('0');}}
    
       l1--;l2--;}

      while(l1>=0){
        if(a[l1]=='1' && carry==1){ans.push_back('0');}
        else if(a[l1]=='0' && carry==1){carry=0;ans.push_back('1');}
        else{ans.push_back(a[l1]);}
        l1--;
      }
      if(carry==1){ans.push_back('1');}
      while(ans.length() !=0 && ans[ans.length()-1] =='0'){ans.pop_back();}
      reverse(ans.begin(),ans.end());
      return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends