#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node*left,*right;
	Node(int data)
	{
		this->data =data;
		left=right=NULL;
	}
};
bool isBSTUtil(struct Node*root,Node*&prev)
{
	if(root)
	{
		if(!isBSTUtil(root->left,prev))
		return false;
		if(prev !=NULL&&root->data<=prev->data)
		return false;
		prev=root;
		return isBSTUtil(root->right,prev);
	}
	return true;
}
bool isBST(Node *root)
{
	Node *prev=NULL;
	return isBSTUtil(root, prev);
}
int main()
{
	struct Node*root=new Node(200);
	root->left=new Node(6);
	root->left->right=new Node(80);
	root->left->right->left=new Node(9);
	root->left->right->left->left=new Node(7);
    root->left->right->left->right=new Node(30);
    root->left->right->left->right->left=new Node(17);
    root->left->right->left->right->right=new Node(65);
    root->left->right->left->right->right->left=new Node(58);
    root->left->right->right=new Node(100);
	root->left->right->right=new Node(150);
if (isBST(root))
cout << "Is BST";
else
cout << "Not a BST";
return 0;
}
