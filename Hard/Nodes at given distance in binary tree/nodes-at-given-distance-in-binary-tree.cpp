//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
   
   Node* findtarget(Node* root,int target){
       if(root==NULL || root->data==target){return root;}
       Node* x=findtarget(root->left,target);
       if(x==NULL){return findtarget(root->right,target);}
       return x;
   }
   
   unordered_map<Node*,Node*> bfs(Node* root){
       unordered_map<Node*,Node*> map;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           Node* node=q.front();
           q.pop();
           if(node->left){
               map[node->left]=node;
               q.push(node->left);}
           if(node->right){
               map[node->right]=node;
               q.push(node->right);}
       }
       return map;
   }
   vector<int> nodesatdistancek(Node* root,int k,unordered_map<Node*,Node*> &parent){
       vector<int> ans;
       unordered_set<Node*> visited;
       visited.insert(root);
       queue<Node*> q;
       q.push(root);
       int curr_level=0;
       while(!q.empty()){
         if(curr_level==k){break;}
         curr_level++;
         int size=q.size();
         while(size--){
         Node* node=q.front();
         q.pop();
         if(parent[node] && visited.find(parent[node])==visited.end()){
             q.push(parent[node]);
             visited.insert(parent[node]);}
         if(node->left && visited.find(node->left)==visited.end()){
             q.push(node->left);
             visited.insert(node->left);}
         if(node->right && visited.find(node->right)==visited.end()){
             q.push(node->right);
             visited.insert(node->right);}
         }
      }
       while(!q.empty()){
           ans.push_back(q.front()->data);
           q.pop();
       }
       return ans;
   }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    { //find target
      Node* Target=findtarget(root,target);
      //find parents of node
      unordered_map<Node*,Node*> parent=bfs(root);
      //find nodes at k distance
      vector<int> ans=nodesatdistancek(Target,k,parent);
      sort(ans.begin(),ans.end());
      return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends