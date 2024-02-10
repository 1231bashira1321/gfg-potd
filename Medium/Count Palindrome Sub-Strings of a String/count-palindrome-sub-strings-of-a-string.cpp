//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends

int countPalindrome(char S[],int start,int end,int N){
        int count=0;
        while(start>=0 && end<N && S[start]==S[end]){
            count++ ; start-- ; end++ ;
        }
        return count;
    }
    
int CountPS(char S[], int N)
{     int count=0;
      for(int i=0;i<N;i++){
       count+=countPalindrome(S,i,i,N)+countPalindrome(S,i,i+1,N); // even + odd length palindrome
      }
      return count-N;
}