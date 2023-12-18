//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
     bool backtrack(int arr[],vector<int>&check,int i,int target,int k,int OGtarget,int size){
        if(target==0){
            if(k==1){return true;}
            return backtrack(arr,check,0,OGtarget,k-1,OGtarget,size);
        }
        if(i==size){return false;}
        bool take=false;
        if(arr[i]<=target && !check[i]){
         check[i]=1;
         take=backtrack(arr,check,i+1,target-arr[i],k,OGtarget,size);
         check[i]=0;
        }
        if(take==true){return true;}
        bool nottake=backtrack(arr,check,i+1,target,k,OGtarget,size);
        return nottake;
        }
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
    int sum=accumulate(a,a+n,0);
    if(sum%k !=0 || n<k){return false;}
    sort(a,a+n,greater<int>());
    vector<int> check(n,0);
    int subsetsum=sum/k;
    return backtrack(a,check,0,subsetsum,k,subsetsum,n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends