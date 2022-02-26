#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* makeNode(int data) {
    struct node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

int findMid(struct node *head,int count) {
    node *f=head,*s=head;
    while(f!=NULL && f->next!=NULL && f->next->next!=NULL) {
        s=s->next;
        f=f->next->next;
    }
    if (count%2==0) {
        cout<<"Middle of Linked List is "<<s->next->data;
    } else {
        cout<<"Middle of Linked List is "<<s->data;
    }
    return 0;
}

int main() {
	struct node *head=NULL,*t;
	int n,count=0;
	while(cin>>n) {
	    count++;
	    if (head==NULL) {
	        head=makeNode(n);
	        t=head;
	    } else {
	        t->next=makeNode(n);
	        t=t->next;
	    }
	}
	findMid(head,count);
	return 0;
}
