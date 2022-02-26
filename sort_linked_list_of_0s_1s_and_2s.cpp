#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* makeNode(int n) {
    struct node *temp=new node;
    temp->data=n;
    temp->next=NULL;
    return temp;
}

int sortList(struct node *head) {
    struct node *t=head,*new_head=head;
    vector<int> v{0,0,0};
    
    // get count of occurances of each number. O(n)
    while (t!=NULL) {
        v[t->data]+=1;
        t=t->next;
    }
    
    // modify the existing list;
    while(new_head!=NULL) {
        if (v[0]!=0) {
            new_head->data=0;
            v[0]-=1;
        } else if (v[1]!=0) {
            new_head->data=1;
            v[1]-=1;
        } else if (v[2]!=0) {
            new_head->data=2;
            v[2]-=1;
        }
        new_head=new_head->next;
    }
    return 0;
}

int printList(struct node *head) {
    struct node *p=head;
    while(p) {
        cout<<p->data<<" --> ";
        p=p->next;
    }
    return 0;
}

int main() {
	struct node *head=NULL,*next;
	int t;
	while (cin>>t) {
	    if (!head) {
	        head=makeNode(t);
	        next=head;
	    } else {
	        next->next=makeNode(t);
	        next=next->next;
	    }
	}
	sortList(head);
	printList(head);
	return 0;
}
