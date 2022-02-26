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

int printLeftView(struct node *root) {
    
    // the idea is to print very first node  
    // that enconters on every new level
    
    if (root==NULL) 
        return 0;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int s=q.size();
        for (int i=1;i<=s;i++) {
            node *temp=q.front();
            q.pop();
            if (i==s)   // only difference 1 --> s
                cout<<temp->data<<" ";
            if (temp->left!=NULL) 
                q.push(temp->left);
            if (temp->right!=NULL) 
                q.push(temp->right);
        }
    }
}

int main() {
	node *root=makeNode(1);
    root->left=makeNode(2);
    root->left->left=makeNode(4);
    root->left->right=makeNode(5);
    root->right=makeNode(3);
    root->right->right=makeNode(6);
    root->right->left=makeNode(7);
    
    printLeftView(root);
	return 0;
}
