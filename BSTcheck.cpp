#include <bits/stdc++.h>
using namespace std;

vector<int> v;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int checkBST(struct node* root,node *prev) {
    if (root) {
        if (!checkBST(root->left,prev)) 
            return 0;
        if (prev!=NULL && root->data<=prev->data)
            return 0;
        prev=root;
        return checkBST(root->right,prev);
    }
    return 1;
}

struct node* makeNode(int item) {
    struct node* temp=new node;
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int main() {
    node *prev=NULL;
    node *root=makeNode(1);
    root->left=makeNode(2);
    root->left->left=makeNode(4);
    root->left->right=makeNode(5);
    root->right=makeNode(3);
    root->right->right=makeNode(6);
    root->right->left=makeNode(7);
	cout<<checkBST(root,prev);
	return 0;
}
