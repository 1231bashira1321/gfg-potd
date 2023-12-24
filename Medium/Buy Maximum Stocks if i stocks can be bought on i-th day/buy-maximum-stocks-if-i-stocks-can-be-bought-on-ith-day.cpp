//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
     vector<pair<int,int>> arr;
     for(int i=0;i<n;i++){
         arr.push_back({price[i],i});}
     sort(arr.begin(),arr.end());
     int stocks=0;
     for(auto it : arr){
         int j=it.second+1;
         while(k>0 && j){
          j--;
          if(k-it.first<0){return stocks;}
          k=k-it.first;
          stocks++;
         }
     }
     return stocks;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends