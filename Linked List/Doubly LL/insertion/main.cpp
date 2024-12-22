#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

Node* constructDLL(vector<int>& arr);
Node* insertAtBegin(Node *head, int x);
Node* insertAtEnd(Node *head, int x);
Node *insertAtPos(Node *head, int pos, int x);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructDLL(arr);
	head = insertAtEnd(head, 8);
	traverse(head);
}

//time: O(n)
//space: O(1)
Node *insertAtEnd(Node *head, int x) {
	// Code here
	if(head == NULL)
	{
		head = new Node(x);
		return head;
	}
	Node* temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	Node* new_node = new Node(x);
	temp->next = new_node;
	new_node->prev = temp;
	return head;
}

//time: O(1)
//space: O(1)
Node *insertAtBegin(Node *head, int x) {
	// Code here
	Node* temp = new Node(x);
	if(head == NULL) return temp;
	head->prev = temp;
	temp->next = head;
	head = temp;
	return head;
}

//insert after posth positon (starting with 0th indexing)
//time: O(n)
//space: O(1)
Node *insertAtPos(Node *head, int pos, int data)
{
	Node* temp = head;
	int i = 0;
	Node* new_node = new Node(data);
	if(head == NULL)
	{
		head = new_node;
		return head;
	}
	while(temp != NULL && i != pos)
	{
		temp = temp->next;
		i++;
	}
	if(temp == NULL)
	{
		cout << "out of bounds" << endl;
		return head;
	}
	if(temp->next != NULL)
	{
		temp->next->prev = new_node;
		new_node->next = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
	return head;
} 

//time: O(n)
//space: O(1)
Node* constructDLL(vector<int>& arr) {
	// code here
	Node* head = new Node(arr[0]);
	Node* temp = head;
	for(int i = 1; i < arr.size(); i++)
	{
		//empty list
		Node* new_node = new Node(arr[i]);
		temp->next = new_node;
		new_node->prev = temp;
		temp = temp->next;
	}
	return head;
}

//time: O(n)
//space: O(1)
void traverse(Node* head)
{
	Node* temp = head;
	cout << "NULL<->";
	while(temp != NULL)
	{
		cout << temp->data << "<->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}