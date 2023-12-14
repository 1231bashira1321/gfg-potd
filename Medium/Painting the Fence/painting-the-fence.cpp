//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    long long countWays(int n, int k){
        // code here
        // see the pattern that same[i] = diff[i-1]
        // diff[i] = total[i-1]*(k-1)
        // total[i] = same[i] + diff[i];
        // here same[i] = number of possibilities with 2 consecutive same
        // diff[i] = number of possibilities that 2 consecutive are not same
        // we want the sum of no 2 consecutive and 2 consecutive because atmost 2 consecutive allowed
        long long MOD=(1000000007);
        long long diff = k;
        long long same = 0;
        long long total = k;
        
        if(n==1){
            return total;
        }
        else{
            for(int i=2;i<=n;i++){
                same = (diff)%MOD;
                diff = (total*(k-1))%MOD;
                total = (same + diff)%MOD;
            }
        }
        return (total)%MOD;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends