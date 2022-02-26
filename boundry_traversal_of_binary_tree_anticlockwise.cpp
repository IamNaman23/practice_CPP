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

int printNodesOnLeftPath(struct node *left_root) {
    if (left_root) {
        if (left_root->left) {
            cout<<left_root->data<<" ";
            printNodesOnLeftPath(left_root->left);
        } else if (left_root->right) {
            cout<<left_root->data<<" ";
            printNodesOnLeftPath(left_root->right);
        }
    }
    return 0;
}

int printNodesOnRightPath(struct node *right_root) {
    if (right_root) {
        if (right_root->right) {
            printNodesOnRightPath(right_root->right);
            cout<<right_root->data<<" ";
        } else if (right_root->left) {
            printNodesOnRightPath(right_root->left);
            cout<<right_root->data<<" ";
        }
    }
    return 0;
}

int printLeafNodes(struct node *leaf) {
    if (leaf==NULL) 
        return 0;
    printLeafNodes(leaf->left);
    if (leaf && !leaf->left && !leaf->right)
        cout<<leaf->data<<" ";
    printLeafNodes(leaf->right);
    return 0;
}

int printBoundryTraversal_Anticlockwise(struct node *root) {
    
    // dividing the problem into 3 parts.
    // Part 1 : print all nodes on left path, from top-to-bottom
    // Part 2 : print all leaf nodes, from left-to-right
    // Part 3 : print all nodes on right path, from bottom-to-top
    // maintaining the order will give the required traversal
    
    if (root==NULL) {
        return 0;
    } else {
        cout<<root->data<<" ";
    }
    printNodesOnLeftPath(root->left);   // Part 1
    printLeafNodes(root->left);         // 
    printLeafNodes(root->right);        // Part 2
    printNodesOnRightPath(root->right); // Part 3
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
    
    printBoundryTraversal_Anticlockwise(root);
	return 0;
}
