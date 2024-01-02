//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        /*
        observation
        find subarray of k size
        can we extend that subarray ? if yes then do it
        */
        vector<long long int> suffix(n,0);
        suffix[n-1]=a[n-1];
        for(long long int i=n-2;i>=0;i--){
         suffix[i]=max(suffix[i+1]+ a[i], a[i]);
        }
        
        long long int subarrsum=0;
        
        for(long long int i=0;i<k;i++){
         subarrsum+= a[i];
        }
      
        long long int ans=subarrsum;
        
        for(long long int i=k;i<n;i++){
         
              ans=max({ans, subarrsum+suffix[i],  subarrsum});
             
              subarrsum= subarrsum+a[i]-a[i-k];
          
        }
        
        ans=max(ans, subarrsum);
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends