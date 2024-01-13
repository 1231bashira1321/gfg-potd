//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
       struct Node* head=head_ref; //head node of output linked list;
       struct Node* last=head;    //last node of output linked list;
       
       struct Node* temp=head_ref->next;
       head_ref->next=NULL;
      
       while( temp !=NULL){
           struct Node* Next=temp->next;
           temp->next=NULL;
           
           if( temp->data >= last->data){
            last->next=temp;
            last=last->next;
           }
        
           else{
              struct Node* curr=head;
              struct Node* prev=NULL;
              while(curr->data < temp->data){
               prev=curr;
               curr=curr->next;
               }
              if(prev==NULL){
               temp->next=head;
               head=temp;
              }
              else {
                prev->next=temp;
                temp->next=curr;
              }
           }
         temp=Next;
       }
       return head;
       
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends