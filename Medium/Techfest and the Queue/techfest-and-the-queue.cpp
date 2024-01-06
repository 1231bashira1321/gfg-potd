//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // creating array to store smallest prime factor of every number
	    vector<int> spf(b+1,0);
	    for(int i=0;i<=b;i++){
	        spf[i]=i;
	    }
	    
	    for(int i=2;i*i<=b;i++){
	        if(spf[i]==i){
	            for(long long int j=i*i;j<=b;j+=i){
	                if(spf[j]==j){
	                    spf[j]=i;  //marking smallest prime factor of j 
	                }
	            }
	        }
	    }
	    //counting sum of powers of prime factorization
	    int sum=0;
	    for(int i=a;i<=b;i++){
	        int num=i;
	        while(num !=1){
	            num=num/spf[num];
	            sum++;
	        }
	    }
	    return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends