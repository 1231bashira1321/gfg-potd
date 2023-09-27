//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
          sort(arr, arr + n);
        sort(brr, brr + m);
        int ans1=arr[0], ans2=arr[0];
        int diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int tm = x - arr[i];
            int left = 0, right = m - 1, mid;
            bool f = 0,f2=0;;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if (brr[mid] == tm)
                {
                    ans1 = arr[i];
                    ans2 = brr[mid];
                    diff=0;
                    f2=1;
                    break;
                }
                else if (brr[mid] > tm)
                {
                    if (diff > abs(brr[mid] + arr[i] - x))
                    {
                        ans1 = arr[i];
                        ans2 = brr[mid];
                         diff=abs(brr[mid] + arr[i] - x);
                    }
                    right = mid;
                }
                else
                {
                    if (diff > abs(brr[mid] + arr[i] - x))
                    {
                        ans1 = arr[i];
                        ans2 = brr[mid];
                        diff=abs(brr[mid] + arr[i] - x);
                    }
                    left = mid + 1;
                }
                if (f)
                    break;
                if (left == right)
                    f = 1;
            }
            if(f2)break;
        }
        vector<int>v;
        v.push_back(ans1);
        v.push_back(ans2);
        // cout<<ans1<<" "<<ans2<<endl;
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends