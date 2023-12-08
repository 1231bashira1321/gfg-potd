//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
      bool isprime(int sum){
        bool t=1;
       if(sum==1)
       return 0;
       
       for(int i=2;i<sum;i++){
           if(sum%i==0){
           t=0;
           break;
           }
       }
       return t;
    }
    int minNumber(int arr[],int N)
    {
         int sum=0;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
        }
        int temp=sum;
  bool t=isprime(sum);
      if(t)
      return 0;
      else{
          for(int i=1;i<10000;i++){
              sum=temp+i;
              if(isprime(sum))
              return i;
          }
      }
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends