//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
     int r=matrix.size();
     int c=matrix[0].size();
     int count=0,ans=0;
     for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
           if(matrix[i][j]==1){
            count=0;
            if(i-1>=0 && matrix[i-1][j]==0){count++;} //up
            if(j+1<c && matrix[i][j+1]==0){count++;} //right
            if(i+1<r && matrix[i+1][j]==0){count++;} //down
            if(j-1>=0 && matrix[i][j-1]==0){count++;} //left
            
            if(i-1>=0 && j-1>=0 && matrix[i-1][j-1]==0){count++;} //up left
            if(i-1>=0 && j+1<c && matrix[i-1][j+1]==0){count++;} //up right
            if(i+1<r && j-1>=0 && matrix[i+1][j-1]==0){count++;} //down left
            if(i+1<r && j+1<c && matrix[i+1][j+1]==0){count++;} //down right
            
            if(count !=0 && count%2==0){ans++;}
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends