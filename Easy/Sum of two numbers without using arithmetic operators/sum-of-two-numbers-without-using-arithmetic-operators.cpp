//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
     /*
    method-1
    add  the numbers in bit format will give the result but coding this will be complex
    eg    7   0 1 1 1
         10   1 0 1 0
        __________________
          17  1 0 0 0 1
        _________________
    */
    /*
    method-2
    doing the XOR operation will give the result and taking care of carry part
    */
    int ans=0;
    int pos=0;
    int carry=0;
    while(a !=0 || b !=0){
        int lba=a & 1;//int last bit of a
        int lbb=b & 1;// int last bit of b
        if(lba==1 && lbb==1){
            if(carry){ ans=ans|(1<<pos);}
            else{carry=1;}}
        else if(lba==0 && lbb==0){
            if(carry==1){carry=0;ans=ans|(1<<pos);}}
        else if (carry==0){ans=ans|(1<<pos); }

        pos++;
        a>>=1;
        b>>=1;
        }
    if(carry){ ans=ans|(1<<pos);}
    return ans;
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}

// } Driver Code Ends