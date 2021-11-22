#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node * link;
};

void printList(Node * n)
{
	while(n!=nullptr){
		cout<<n->data<<endl;
		n = n->link;
	}
}

void insertAtTheFront(Node ** head, int newValue)
{
	//1. Prepare a newNode
	Node * newNode = new Node();
	newNode->data = newValue;
	//2. Put it in front of current head
	newNode->link = *head;
	//3. Move head of the list to point to the newNode
	*head = newNode;

}
/*
	implementation using user define data type
	
	Node * insertAtTheFront(Node * head, int newValue)
	{
		Node * newNode = new Node();
		newNode->data = newValue;
		newNode->link = head;
		head = newNode;
		return head;
	}
*/

void insertAtTheEnd(Node ** head, int newValue)
{
	//1. Prepare a newNode
	//2. If Linked list is empty, newNode will be a head node
	//3. Find the last node
	//4. Insert newNode after last one (at the end)
	
}

int main(){
	Node * head = new Node();
	Node * second = new Node();
	Node * third = new Node();	

	head->data = 1;
	head->link = second;
	second->data = 2;
	second->link = third;
	third->data = 3;
	third->link = nullptr;

	insertAtTheFront(&head, 0);
	insertAtTheFront(&head, -1);
	printList(head);
	
	return 0;
}