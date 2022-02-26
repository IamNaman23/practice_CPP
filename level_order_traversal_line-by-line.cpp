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

int printBFS(struct node *root) {
    queue<struct node*> q;
    struct node *temp;
    q.push(root);
    while (!q.empty()) {
        temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
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
    
    //printing level order traversal
    printBFS(root);
    
	return 0;
}
