//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{  long long int solve(string &s,int k){
    //counting subarrays having at most k charaters
    int n=s.length();
    if(n==0){return 0;}
    long long int cnt=0;
    int start=0;
    vector<int> map(26,0);
    int distinct_char=0;
    for(int i=0;i<n;i++){
        if(map[s[i]-'a']==0){distinct_char++;}
        map[s[i]-'a']++;
        while(distinct_char>k){
            map[s[start]-'a']--;
            if(map[s[start]-'a']==0){distinct_char--;}
            start++;}
        cnt+=i-start+1;
    }
    return cnt;
}
  public:
    long long int substrCount (string s, int k) {
    return solve(s,k)-solve(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends