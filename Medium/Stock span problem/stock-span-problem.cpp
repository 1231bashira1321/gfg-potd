//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans(n);
       stack<int> st; //stores index
       reverse(price,price+n);
       for(int i=n-1;i>=0;i--){
          while( !st.empty() && price[st.top()]<=price[i]){
              st.pop();
          }
          if(st.empty()){ ans[i]=n-i ; st.push(i); }
          else{          //st.top()>price[i]
            ans[i]=st.top()-i;
            st.push(i);
          }
       }
       reverse(ans.begin(),ans.end());
       return ans;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends