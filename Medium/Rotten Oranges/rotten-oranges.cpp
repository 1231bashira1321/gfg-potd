//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
     int R=grid.size();
     int C=grid[0].size();
     queue<pair<int,pair<int,int>>> q;
     for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
          if(grid[i][j]==2){q.push({0,{i,j}});}}}
     int cnt=0;
     while(!q.empty()){
         cnt=q.front().first;
         int r=q.front().second.first;
         int c=q.front().second.second;
         q.pop();
         int dx[]={-1,0,1,0};
         int dy[]={0,1,0,-1};
         for(int i=0;i<4;i++){
          int new_row=r+dx[i];
          int new_col=c+dy[i];
              if(new_row>=0 && new_row<R && new_col>=0 && new_col<C && grid[new_row][new_col]==1){
                  grid[new_row][new_col]=2;
                  q.push({cnt+1,{new_row,new_col}});}
              }
     }
     //queue empty now check if fresh tomatoes are available
     for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
          if(grid[i][j]==1){return -1;}}}
          return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends