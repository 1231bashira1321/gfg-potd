//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int  find_and(int l, int r ) 
    { //If any column in a 32 bit number is 0 then that column will remain 0 for any number of bitwise and operation
      //observations
      //All column of rightside of the flipped bit is also flipped that means all columns of the rightside of the flipped bit will remain 0
      //Leftmost consecutive element in (left,right) range are always fixed in given range
      int count=0;
      while(l !=r){
          l>>=1;
          r>>=1;
          count++;
      }
      return l<<count;
        
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int  l, r;
    	cin >> l >> r;
    	Solution ob;
    	int ans = ob.find_and(l, r);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends