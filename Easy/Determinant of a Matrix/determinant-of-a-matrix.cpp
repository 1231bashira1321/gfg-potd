//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here
        if(n==1){
            return matrix[0][0] ;
        }
        
        int prod  = 0;
        
        for(int i = 0 ; i<1 ; i++){
            for(int j = 0 ; j<matrix[i].size() ; j++){
                vector<vector<int>> temp(n-1, vector<int>(n-1));
                int nexr = 0 , nexc ;
                for(int row = i+1; row<n ; row++, nexr++){
                    
                    for(int col = 0, nexc = 0; col<matrix[row].size(); col++, nexc++){
                        if(col==j) {nexc-- ; continue;}
                                
                        temp[nexr][nexc] = matrix[row][col] ;
                        
                    }
                }
                
                int sign = j%2==0?1:-1;
                prod += sign*matrix[i][j]*determinantOfMatrix(temp, n-1) ;
            }
        }
        
        return prod ;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends