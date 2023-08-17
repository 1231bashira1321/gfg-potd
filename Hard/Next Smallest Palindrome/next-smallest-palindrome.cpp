//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    bool change=true;
        
        for(int i=0 ; i<n/2 ; i++)
        {
            if(num[i]<num[n-i-1])
            {
                change=true;
            }
            else if(num[i]>num[n-i-1]){
                change =false;
            }
            num[n-i-1]=num[i];
        }
        vector<int>ans(n);
        for(int i=0 ; i<n ; i++)
        {
            ans[i]=num[i];
        }
        
        int index=n/2;
        
        bool carry=change;
        
        while(carry && index<n)
        {
            if(ans[index]==9)
            {
                ans[index]=0;
                ans[n-index-1]=0;
            }
            else{
                ans[index]++;
                ans[n-index-1]=ans[index];
                carry=0;
            }
            index++;
        }
        if(carry)
        {
            ans.push_back(1);
            ans[0]=1;
        }
        return ans;
        
	   
	   
	   
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends