//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node*revL(Node*head){
        Node*fol=head,*cur=NULL,*prev=NULL;
        while(fol){
            cur=fol;
            fol=fol->next;
            cur->next=prev;
            prev=cur;
        }
        return cur;
    }

 

    Node* subLinkedList(Node* head1, Node* head2) {
        int n=0,m=0;
        Node*h1=head1,*h2=head2;

//count size of head1 and erase 0 first
        while(head1 && h1){
            n++;
            if(head1->data==0){
                Node*t=head1;
                head1=head1->next;
                delete t;
                n--;
                h1=head1;
            }
            else{
                h1=h1->next;
            }
        }

//count size of head2 and erase 0 first
        while(head2 && h2){
            m++;
            if(head2->data==0){
                Node*t=head2;
                head2=head2->next;
                delete t;
                m--;
                h2=head2;
            }
            else{
                h2=h2->next;
            }
        }

//check if 2 head is 0
        if(!head1 && !head2){
            return new Node(0);
        }

//find higher and lower in value of all linked list
        Node*hg=NULL,*lw=NULL;
        if(n>m){
            hg=head1;
            lw=head2;
        }
        else if( n<m){
            hg=head2;
            lw=head1;
        }
        else{ // if (n==m)
            h1=head1;
            h2=head2;
            while(h1 && h2 && h1->data==h2->data){
                h1=h1->next;
                h2=h2->next;
            }
            if(!h1 && !h2){
                return new Node(0);
            }
            if(h1->data>h2->data){
                hg=head1;
                lw=head2;
            }
            else{
                hg=head2;
                lw=head1;
            }
        }

//substract the lower from higher linkedlist
        hg=revL(hg);
        lw=revL(lw);
        bool fl=0;
        h1=hg,h2=lw;
        while(h1 && h2){
            h1->data-=fl;
            if(h1->data<h2->data){
                h1->data+=10;
                h1->data-=h2->data;
                fl=1;
            }
            else{
                h1->data-=h2->data;
                fl=0;
            }
            h1=h1->next;
            h2=h2->next;
        }

//if higher need to pay for its borrowed 1 last value
        while(h1 && fl){
            if(h1->data==0){
                h1->data=9;
                fl=1;
            }
            else{
                h1->data-=1;
                fl=0;
            }
            h1=h1->next;
        }

//reverse higher, erase 0 first then return 
        hg=revL(hg);
        h1=hg;
        while(hg && h1){
            n++;
            if(hg->data==0){
                Node*t=hg;
                hg=hg->next;
                delete t;
                n--;
                h1=hg;
            }
            else{
                h1=h1->next;
            }
        }
        if(!hg){
            return new Node(0);
        }
        return hg;
        return NULL;
    }


};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends