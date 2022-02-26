#include<bits/stdc++.h>
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

int printRightPath (struct node* root) {
    struct node *r=root;
    while(r) {
        cout<<r->data<<" ";
        r=r->right;
    }
    return 0;
}

int printLeftPath (struct node* root) {
    struct node *l=root;
    while(l) {
        cout<<l->data<<" ";
        l=l->left;
    }
    return 0;
}

int printTopView(struct node* root) {
    if (root) {
        cout<<root->data<<" ";
        printLeftPath(root->left);
        printRightPath(root->right);
    }
    return 0;
}

int main() {
    node *root=makeNode(1);
    root->left=makeNode(2);
    root->left->left=makeNode(4);
    root->left->right=makeNode(5);
    root->right=makeNode(3);
    root->right->right=makeNode(6);
    root->right->left=makeNode(7);
    
    cout<<printTopView(root);
    
    return 0;
}