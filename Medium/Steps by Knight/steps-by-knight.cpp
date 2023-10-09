//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	  queue<pair<int,pair<int,int>>> q;
	 q.push({0,{KnightPos[0],KnightPos[1]}});
	 vector<vector<int>>visited(N+1,vector<int>(N+1,0));
	 visited[KnightPos[0]][KnightPos[1]]=1;
	 int minsteps=0;
	 while(!q.empty()){
	   minsteps=q.front().first;
	   int r=q.front().second.first;
	   int c=q.front().second.second;
	   q.pop();
	   if(r==TargetPos[0] && c==TargetPos[1]){return minsteps;}
	   int dx[]={1,1,-1,-1,2,2,-2,-2};
	   int dy[]={2,-2,2,-2,1,-1,1,-1};
	   for(int i=0;i<8;i++){
	       int new_row=r+dx[i];
	       int new_col=c+dy[i];
	       if(new_row>=1 && new_row<=N && new_col>=1 && new_col<=N && visited[new_row][new_col]==0){
	           visited[new_row][new_col]=1;
	           q.push({minsteps+1,{new_row,new_col}});
	       }
	   }
	 }
	 return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends