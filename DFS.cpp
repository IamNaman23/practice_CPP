#include <bits/stdc++.h>
using namespace std;

map<int,bool> visited;
vector<int> dfs;

struct node {
    int data;
    struct node*left;
    struct node*right;
};

stack<struct node*> s;

int DFS(struct node *root) {
    if (!root) 
        return 0;
    if (root && visited[root->data]==false) {
        dfs.push_back(root->data);
        visited[root->data]=true;
        s.push(root);
    }
    if (root->left)
        DFS(root->left);
    if (root->right)
        DFS(root->right);
    s.pop();
    return 0;
}

struct node* makeNode(int item) {
    struct node* temp=new node;
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int main() {
	node *root=makeNode(1);
    root->left=makeNode(2);
    root->left->left=makeNode(4);
    root->left->right=makeNode(5);
    root->right=makeNode(3);
    root->right->right=makeNode(6);
    root->right->left=makeNode(7);
    visited[1]=false;
    visited[2]=false;
    visited[4]=false;
    visited[5]=false;
    visited[3]=false;
    visited[6]=false;
    visited[7]=false;
    DFS(root);
    for (auto i:dfs)
        cout<<i<<" ";
	return 0;
}
