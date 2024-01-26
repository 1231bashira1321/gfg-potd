//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution{
    
    public:
    static bool compareItem(Item i1, Item i2){
        double a=i1.value/(double)i1.weight;
        double b=i2.value/(double)i2.weight;
        return a > b;}
 
    double fractionalKnapsack(int W, Item arr[], int n)
    {sort(arr,arr+n,compareItem);
     double maxValue=0;
     for(int i=0;i<n;i++){
      if(W>=arr[i].weight){
         maxValue+=arr[i].value;
         W-=arr[i].weight;
        } else {
            double val=(arr[i].value/(double)arr[i].weight)* W;
            maxValue+=val;
            break;}  
     }
    return maxValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends