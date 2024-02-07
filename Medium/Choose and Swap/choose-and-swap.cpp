//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string s){
        int curr=0;
        char x,y;
        int n=s.length();
        unordered_set<char> st;
        
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            for(int j=i+1;j<n;j++){
                if( (curr < (s[i]-s[j]) ) && (st.find(s[j])==st.end()) ){
                    curr=s[i]-s[j];
                    x=s[i];
                    y=s[j];
                }
            }
            if(curr !=0){ break; }
        }
        
        
        if(curr==0){ return s; }
        
        for(int i=0;i<n;i++){
            if(s[i]==x){ s[i]=y; }
            else if(s[i]==y){ s[i]=x; }
        }
        return s;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends