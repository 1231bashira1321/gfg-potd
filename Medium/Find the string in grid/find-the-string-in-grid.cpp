//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool search(vector<vector<char>>grid, string word,int r,int c){
        
     if(word[0] !=grid[r][c]){return false;}
     
     int dx[]={-1,-1,0,1,1,1,0,-1};
     int dy[]={0,1,1,1,0,-1,-1,-1};
     
     for(int i=0;i<8;i++){
       int new_r=r;
       int new_c=c;
       int j=0;  
       for(j=0;j<word.length();j++){
         if(new_r>=0 && new_c>=0 && new_r<grid.size() && new_c<grid[0].size() && grid[new_r][new_c]==word[j]){
          new_r=new_r+dx[i];
          new_c=new_c+dy[i];
         }
         else{
             break;
         }
           
       }
       if(j==word.length()){return true;}
     }
     return false;
    }
    
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	 int r=grid.size();
	 int c=grid[0].size();
	 vector<vector<int>> ans;
	 for(int i=0;i<r;i++){
	     for(int j=0 ;j<c;j++){
	        if(search(grid,word,i,j)){
	         vector<int> pos={i,j};
	         ans.push_back(pos);
	        }
	     }
	 }
	 return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends