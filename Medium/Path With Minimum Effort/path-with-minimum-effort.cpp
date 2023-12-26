//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
    int row=heights.size();
    int col=heights[0].size();
    vector<vector<int>> dist(row,vector<int>(col,1e9));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}}); //effort row column
    vector<vector<int>> path={{-1,0},{0,1},{1,0},{0,-1}};
    while(!pq.empty()){
     int currEffort=pq.top().first;
     int r=pq.top().second.first;
     int c=pq.top().second.second;
     pq.pop();
     if(r==row-1 && c==col-1){return currEffort;}
     for(auto it : path){
       int nr=r+it[0];
       int nc=c+it[1];
       if(nr>-1 && nr< row && nc>-1 && nc<col){
           int newEffort=max(currEffort,abs(heights[nr][nc]-heights[r][c]));
           if(newEffort<dist[nr][nc]){
               dist[nr][nc]=newEffort;
               pq.push({newEffort,{nr,nc}});}
       }
     }
    }
    return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends