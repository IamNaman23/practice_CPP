#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node* makeNode(int item) {
    struct node* temp=new node;
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node *dh=NULL,*t;

int findLeaves(struct node* root) {
    if (!root->left && !root->right) {  // it is a leaf node
        if (dh==NULL) {
            dh=root;
            dh->left=NULL;
            t=dh;
        } else {
            root->left=t;
            t->right=root;
            t=root;
        }
        return 0;
    }
    if (root->left) 
        findLeaves(root->left);
    if (root->right)
        findLeaves(root->right);
    return 0;
}

int printList_Right() {
    struct node *r=dh;
    while (r) {
        cout<<r->data<<" --> ";
        r=r->right;
    }
    return 0;
}

int printList_Left() {
    struct node *l=t;
    while (l) {
        cout<<l->data<<" --> ";
        l=l->left;
    }
    return 0;
}

int main() {
    
    // making the tree
	node *root=makeNode(1);
    root->left=makeNode(2);
    root->left->left=makeNode(4);
    root->left->right=makeNode(5);
    root->right=makeNode(3);
    root->right->left=makeNode(7);
    root->right->right=makeNode(6);
    
    // finding leaves
    findLeaves(root);
    
    // print doubly Linked List
    printList_Right();
    cout<<endl;
    printList_Left();
	return 0;
}