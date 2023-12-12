//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// 25
// 2512 -91024 -24541 76954 -93205 2512 -24541 54236 -63032 15254 50364 -63032 15254 15254 76954 50364 -63032 -91024 54236 50364 -24541 54236 76954 2512 -91024
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
     vector<int> count(32,0);
     int ans=0;
     for(int pos=0;pos<32;pos++){
         int sum_bits_at_ith_pos=0;
         for(int i=0;i<N;i++){
             if(  (arr[i]>>pos) & 1 ){sum_bits_at_ith_pos++;}
         }
        if ( (sum_bits_at_ith_pos  % 3) !=0){ans+=1<<pos;}
     }
     return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends