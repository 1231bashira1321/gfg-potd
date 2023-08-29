//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Pair{
  public:
  Node *head;
  Node *tail;
};

class Solution
{   Pair reverse(Node *head){
      if (head==NULL || head->next==NULL){
       Pair ans;
       ans.head=head;
       ans.tail=head;
       return ans;}
      Pair newhead=reverse(head->next);
      newhead.tail->next=head;
      head->next=NULL;
      Pair ans;
      ans.head=newhead.head;
      ans.tail=head;
      return ans;}

    Node* reverse2(Node *head){
      return reverse(head).head;}
   
    public:
    Node *compute(Node *head)
    {head=reverse2(head);
     Node *curr=head;
     while(curr !=NULL){
      if(curr->next !=NULL && curr->data>curr->next->data) {
          curr->next=curr->next->next;
      }
      else{curr=curr->next;}
     }
    
    return reverse2(head);}
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends