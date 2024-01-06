//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
   	long long int prime_Sum(int n){
   	
     vector<bool> isprime(n+1,true);
     isprime[0]=false;  // 0 is not a prime number
     isprime[1]=false;  // 1 is not a prime number
     for(int i=2 ;i<=n ;i++){
         if(isprime[i]==true){ //if marked false then all its multiple is also marked and it is not a prime number
          for(long long int j=1LL*i*i ; j<=n;j+=i){ //as marking multiples of i so jump through i
           isprime[j]=false; //not a prime number
          }
         }
     }
     
     long long int ans=0;
     for(int i=2;i<=n;i++){
         if(isprime[i]){
             ans+=i;
         }
     }
     return ans;
    
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		long long int ans = ob.prime_Sum(n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends