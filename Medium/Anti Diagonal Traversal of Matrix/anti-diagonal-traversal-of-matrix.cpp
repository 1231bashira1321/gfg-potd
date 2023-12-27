//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        
     int row=matrix.size();
     int col=matrix[0].size();
     vector<int> ans;
     for(int i=0;i<col;i++){
      int r=0;
      int c=i;
      while(c>=0){
          ans.push_back(matrix[r][c]);
          r++;
          c--;
      }
     }
     for(int i=1;i<row;i++){
      int r=i;
      int c=col-1;
      while(r<row){
          ans.push_back(matrix[r][c]);
          r++;
          c--;
      }
     }
     
     return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends