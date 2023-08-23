//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{ int r=grid.size();
	  int c=grid[0].size();
	  queue<pair<pair<int,int>,int>> q; //row,col,step
	  vector<vector<int>> vis(r,vector<int>(c,0));
	  vector<vector<int>> dist(r,vector<int>(c,0));
	  
	  for(int i=0;i<r;i++){
	      for(int j=0;j<c;j++){
	        if(grid[i][j]==1){
	            q.push({{i,j},0});
	            vis[i][j]=1;
	        }}}
	  int dx[]={-1,0,1,0};
	  int dy[]={0,1,0,-1};
	  while(!q.empty()){
	    auto i=q.front();
	    q.pop();
	    int row=i.first.first;
	    int col=i.first.second;
	    int steps=i.second;
	    dist[row][col]=steps;
	    for(int i=0;i<4;i++){
	        int new_r=row+dx[i];
	        int new_c=col+dy[i];
	        if(new_r>=0 && new_r<r && new_c>=0 && new_c<c && vis[new_r][new_c]==0){
	         vis[new_r][new_c]=1;
	         q.push({{new_r,new_c},steps+1});
	        }
	    }
	  }
	  return dist;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends