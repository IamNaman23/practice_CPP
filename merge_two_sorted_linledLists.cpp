#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* printMergedList(struct node *h) {
    struct node *head=h;
    while (h!=NULL) {
        cout<<h->data;
        h=h->next;
    }
    return head;
}

struct node* mergeLists(struct node *h1,struct node *h2) {
    struct node *h,*t;
    if (h1->data<h2->data) {    // insert node from L1
        h=h1;
        h1=h1->next;
        h->next=NULL;
    } else {                    // insert node from L2
        h=h2;
        h2=h2->next;
        h->next=NULL;
    }
    t=h;
    while (h1!=NULL && h2!=NULL) {
        if (h1->data<h2->data) {    // insert node from L1
            t->next=h1;
            h1=h1->next;
        } else {                    // insert node from L2
            t->next=h2;
            h2=h2->next;
        }
        t=t->next;
        t->next=NULL;
    }
    
    // we come here when either of the two lists have exhausted
    if (h1==NULL) {
        t->next=h2;
    } else {
        t->next=h1;
    }
    
    // finally printing merged list
    return printMergedList(h);
}

struct node* makeNode(int data) {
    struct node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

int main() {
	struct node *head,*head1,*head2,*tail1,*tail2;
	
	// making first linked list
	head1=makeNode(1);
	tail1=head;
	tail1->next=makeNode(3);
	tail1=tail1->next;
	tail1->next=makeNode(5);
	tail1=tail1->next;
	
	// making second linked list
	head2=makeNode(2);
	tail2=head;
	tail2->next=makeNode(4);
	tail2=tail2->next;
	tail2->next=makeNode(6);
	tail2=tail2->next;
	
	
	//cannot use merge procedure from mergeSort
	// because merging has to be done inplace.
	head=mergeLists(head1,head2);
	
	return 0;
}
