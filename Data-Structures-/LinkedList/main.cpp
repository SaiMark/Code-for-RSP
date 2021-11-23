#include<iostream>
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
	Node* newNode = new Node();
	newNode->data = newValue;
	newNode->link = nullptr;
	//2. If Linked list is empty, newNode will be a head node
	if(*head == nullptr){
		*head = newNode;
		return;
	}
	//3. Find the last node
	Node* last = *head;
	while(last->link!=nullptr){
		last = last->link;
	}
	//4. Insert newNode after last one (at the end)
	last->link = newNode;
}

/*
	implementation using user define data type;
	Node* insertAtTheEnd(Node * head, int newValue)
	{
		Node * newNode = new Node();
		newNode->data = newValue;
		newNode->link = nullptr;

		Node* last = head;
		while(last->link!=nullptr){
			last = last->link;
		}
		last->link = newNode;
		return head;
	}
*/

void insertAfter(Node* previous, int newValue)
{
	//1. Check if previous node is nullptr
	if(previous == nullptr){
		cout<<"Previous can not be nullptr"<<endl;
		return;
	}
	//2. Prepare newNode
	Node* newNode = new Node();
	newNode->data = newValue;
	//3. Insert newNode after previous
	newNode->link = previous->link;
	previous->link = newNode;
}

void searchInsert(Node**head, int newValue, int index)
{
	//Create a new Node
	Node* newNode = new Node();
	newNode->data = newValue;

	//Searching for the position inside of the linked list
	Node* temp = *head;
	for(int i=0;i<index-1;i++){
		if(temp->link!=nullptr){
			temp=temp->link;
		}
	}

	//Linked the newnode to the next node
	newNode->link=temp->link;
	//Link the previous node to the newNode
	temp->link=newNode;
}

void deletion(Node* head, int value)
{
	//Fast implementation;
	Node* temp = head;
	while(temp->link!=nullptr){
    	if(temp->link->data==value)
    	{
    		temp->link=temp->link->link;
    	}
    	else
    	{
    		temp=temp->link;
    	}
    }
}

/*
	Better way to implement deletion of node
	Because the previous code do not have use delete
	So at the end, it just link two part together but not delete the node in heap
void deletion(Node* head, int value)
{
	Node * temp = head;
	while(temp->link->data!=value)
	{
		temp = temp->link;
	}
	Node*todelete = temp->link;
	temp->link = temp->link->link;

	delete todelete;
}
*/

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

	insertAfter(head, 1);
	insertAtTheFront(&head, 0);
	insertAtTheFront(&head, -1);
	insertAtTheEnd(&head,4);
	insertAtTheEnd(&head,5);
	searchInsert(&head,100, 4);
	deletion(head,3);
	printList(head);
	
	return 0;
}