//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
     set<int> str;
     set<int> stc;
     int Row=matrix.size();
     int Col=matrix[0].size();
     for(int i=0;i<Row;i++){
         for(int j=0;j<Col;j++){
             if(matrix[i][j]==1){
                 str.insert(i);
                 stc.insert(j);
             }
         }
     }
     set<int> :: iterator itr1;
     for(itr1=str.begin();itr1 !=str.end();itr1++){
         for(int c=0;c<Col;c++){
             matrix[*(itr1)][c]=1;
         }
     }
     set<int> :: iterator itr2;
     for(itr2=stc.begin();itr2 !=stc.end();itr2++){
         for(int r=0;r<Row;r++){
             matrix[r][(*itr2)]=1;
         }
     }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends