//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution
{
    public:
    
        vector<int> prefix(string pat , int n){
            vector<int> pi(n,0);
            int pre =0;
            int suf=1;
            while(suf<n){
                if(pat[pre]==pat[suf]){
                    pi[suf]=pre+1;
                    pre++;
                    suf++;
                }
                else{
                    if(pre==0){
                        pi[suf]=0;
                        suf++;
                    }
                    else{
                        pre = pi[pre-1];
                    }
                }
            }
            
            return pi;
        }
        vector <int> search(string pat, string txt)
        {
        vector<int> pi=prefix(pat,pat.size());
        vector<int> ans;
            int p1=0;
            int p2=0;
            while(p1<txt.size()){
                if(txt[p1]==pat[p2] and p2<pat.size() ){
                    p1++;
                    p2++;
                }
                else{
                    if(p2==0){
                        p1++;
                    }
                    else{
                        p2=pi[p2-1];
                    }
                    
                }
                if(p2==pat.size()){
                        ans.push_back(p1-pat.size()+1);
                        p2=pi[p2-1];
                    }
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends