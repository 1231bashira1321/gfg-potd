//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int val){
     left=NULL;
     right=NULL;
     data=val;
    }
};


class Solution{
    
    void successor(Node* root,int val,int& ans){
    if(root==NULL){ return ; }
    if(root->data>val){
        ans=root->data;
        successor(root->left,val,ans);
    } else {
        successor(root->right,val,ans); }
    return;
}

    Node* insert(Node* root,int val){
    if(root==NULL){ 
        Node *newnode= new Node(val);
        return newnode; }
    if(root->data>val){
        root->left=insert(root->left,val);
    } else {
        root->right=insert(root->right,val); }
    return root;
}

    
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root=NULL;
        for(int i=n-1;i>=0;i--){
            int ans=-1;
            successor(root,arr[i],ans);
            root=insert(root,arr[i]);
            arr[i]=ans;
        }
    
        return arr;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends