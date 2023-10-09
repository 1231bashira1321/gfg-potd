//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int> toposort(vector<vector<int>>& adj,int v){
     vector<int> indegree(v,0);
     vector<int> topo;
     queue<int> q;
     for(int i=0;i<v;i++){
         for(auto neigh : adj[i])
             {indegree[neigh]++;}}
     
     for(int i=0;i<v;i++){
      if(indegree[i]==0){q.push(i);}}
      
     while(!q.empty()){
         int node=q.front();
         q.pop();
         topo.push_back(node);
         for(auto neigh : adj[node]){
             indegree[neigh]--;
             if(indegree[neigh]==0){q.push(neigh);}}
     }
     return topo;
    }
    public:
    string findOrder(string dict[], int N, int K) {
     //create adj matrix to store DAG
     vector<vector<int>> adj(K);
     //create connection between vertices
     for(int i=0;i<N-1;i++){
         int l=min(dict[i].length(),dict[i+1].length());
         for(int j=0;j<l;j++){
             if(dict[i][j] !=dict[i+1][j]){
                 int u=dict[i][j]-'a';
                 int v=dict[i+1][j]-'a';
                 adj[u].push_back(v);
                 break;}
         }
         
     }
     //create toposort
     vector<int> topo=toposort(adj,K);
     //create string ans
     string ans="";
     for(auto i : topo){
         ans.push_back(i+'a');
     }
     return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends