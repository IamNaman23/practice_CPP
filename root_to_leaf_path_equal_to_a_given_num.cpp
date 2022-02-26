#include <iostream>
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

int rootToLeafPath(struct node *root,int sum) {
    sum-=root->data;
    int ans=0;
    if (sum==0 && root->left==NULL && root->right==NULL)
        return 1;
    if (root->left)
        ans=ans||rootToLeafPath(root->left,sum);
    if (root->right)
        ans=ans||rootToLeafPath(root->right,sum);

    return ans;
}

int main() {
	node *root=makeNode(1);
    root->left=makeNode(2);
    root->left->left=makeNode(4);
    root->left->right=makeNode(5);
    root->right=makeNode(3);
    root->right->right=makeNode(6);
    root->right->left=makeNode(7);
    int sum=1;
    if (rootToLeafPath(root,sum)) {
        cout<<"Path Found ;)";
    } else {
        cout<<"Path not Found :(";
    }
	return 0;
}
