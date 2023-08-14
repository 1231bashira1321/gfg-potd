//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {int n=nums.size();
     int result=0;
     for(int i=0;i<n;i++){
      result=result^nums[i];
     }
     int set_bit_no = result & ~(result - 1);
     int x=0,y=0;
     for(int i=0;i<n;i++){
       if(nums[i] & set_bit_no) {
         x=x^nums[i];}
       else{
         y=y^nums[i];}
     }
     if(x>y)
     { return {y,x};}
     else
     { return {x,y};}
    }
   
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends