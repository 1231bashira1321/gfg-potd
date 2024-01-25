//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    bool isprime(int n) {
        if(n == 1)
            return false;
        
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0)
                return false;
                
        return true;
    }
public:
    int solve(int Num1,int Num2)
    {   
    //   //sieve of arthesis
    //   vector<bool>prime(100000,true);
    //   prime[0]=prime[1]=false;
    //   for(int i=2;i<100000;i++){
    //       for(int j=2;i*j<100000;j++){
    //              prime[i*j]=false;}
    //  }
      //convert into string
      string src=to_string(Num1);
      string dst=to_string(Num2);
      //find shortest path
      queue<pair<string,int>>q;
      q.push({src,0}); //number,distance
      vector<int> visited(1e5,0);
      
      
      while(!q.empty()){
          string num=q.front().first;
          int dis=q.front().second;
          visited[stoi(num)]=1;
          if(num==dst){return dis;}
          q.pop();
          
          for(int i=0;i<4;i++){
              char prevDigit=num[i];
              for(char ch='0';ch<='9';ch++){
                  
                  num[i]=ch;
                  int newNum=stoi(num);
            
                  if(!visited[newNum] && isprime(newNum) && newNum>=1000){
                    visited[newNum]=1;
                    q.push({to_string(newNum),dis+1});
                  }
                  
              }
              num[i]=prevDigit;
              
          }
      }
      return -1;
    }
};



//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends