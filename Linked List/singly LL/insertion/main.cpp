#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* constructLL(vector<int>& arr);
Node* insertAtBegin(Node *head, int x);
Node* insertAtEnd(Node *head, int x);
Node *insertAtPos(Node *head, int pos, int x);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	head = insertAtPos(head, 8, 23);
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
	temp->next = new Node(x);
	return head;
}

//time: O(1)
//space: O(1)
Node *insertAtBegin(Node *head, int x) {
	// Code here
	Node* temp = new Node(x);
	if(head == NULL) return temp;
	temp->next = head;
	head = temp;
	return head;
}

//time: O(n)
//space: O(1)
Node *insertAtPos(Node *head, int pos, int x)
{
	if(pos == 1) return insertAtBegin(head, x);
	Node* temp = head;
	Node* new_node = new Node(x);
	int i = 1;
	while(temp != NULL && i != pos - 1)
	{
		temp = temp->next;
		i++;
	}
	if(temp == NULL)
	{
		cout << "out of bounds" << endl;
		return head;
	}
	new_node->next = temp->next;
	temp->next = new_node;
	return head;
} 

//time: O(n)
//space: O(n)
Node* constructLL(vector<int>& arr) {
	// code here
	Node* head = new Node(arr[0]);
	Node* temp = head;
	int length = arr.size();
	for(int i = 1; i < length; i++)
	{
		temp->next = new Node(arr[i]);
		temp = temp->next;
	}
	return head;
}

//time: O(n)
//space: O(1)
void traverse(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}