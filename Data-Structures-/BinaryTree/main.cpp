#include<iostream>
using namespace std;
/*
	Demo Tree
			50
		   /  \
		 30    70
		/  \   / \
	  20  40  60 80
*/
struct Node{
	int data;
	Node* left;
	Node* right;
	//Data input
	Node(){
		data = 0;
		left = nullptr;
		right = nullptr;
	}
	Node(int value){
		data=value;
		left=nullptr;
		right=nullptr;
	}
};

struct Node* Insert(Node* root,int value)
{
	if(!root)
		return new Node(value);
	if(value > root->data)
	{
		root->right = Insert(root->right,value);
	}
	else{
		root->left = Insert(root->left,value);
	}
	return root;
}

struct Node* find_minimum(Node* t)
{
	Node* temp = new Node();
	
	if(t == nullptr){
		return nullptr;
	}

	temp = t;
	while(temp->left!=nullptr){
		temp = temp->left;
	}

	return temp;
}

void Inorder(Node* root)
{
	if(!root)
	{
		return;
	}
	Inorder(root->left);
	cout<<root->data<<endl;
	Inorder(root->right);
}

void Preorder(Node*root)
{
	if(!root)
	{
		return;
	}
	cout<<root->data<<endl;
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(Node*root)
{
	if(!root)
	{
		return;
	}

	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<endl;
}

int main()
{
	Node* root = new Node(50);
	Insert(root, 30);
	Insert(root, 20);
	Insert(root, 40);
	Insert(root, 70);
	Insert(root, 60);
	Insert(root, 80);
	Preorder(root);
	//find_minimum(root);
	return 0;
}