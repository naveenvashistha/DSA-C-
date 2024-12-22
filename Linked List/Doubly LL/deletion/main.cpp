#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node* constructDLL(vector<int>& arr);
Node* deleteAtBegin(Node* head);
Node* deleteAtEnd(Node* head);
Node* deleteAtPos(Node* head, int pos);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructDLL(arr);
	head = deleteAtEnd(head);
	traverse(head);
}

//time: O(1)
//space: O(1)
Node* deleteAtBegin(Node* head)
{
	Node* temp = head;
	if(head->next != NULL)
	{
		head->next->prev = NULL;
	}
	head = head->next;
	delete temp;
	return head;
} 

//time: O(n)
//space: O(1)
Node* deleteAtEnd(Node* head)
{
	Node* temp = head;
	if(head->next == NULL)
	{
		delete head;
		return NULL;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	delete temp;
	return head;
}

//time: O(n)
//space: O(1)
Node* deleteAtPos(Node* head, int pos)
{
	Node* temp = head;
	if(pos == 1)
	{
		head->next->prev = NULL;
		head = head->next;
		delete temp;
		return head;
	}
	for(int i = 1; i < pos; i++)
	{
		temp = temp->next;
	}
	if(temp->next == NULL)
	{
		temp->prev->next = NULL;
		delete temp;
		return head;
	}
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	delete temp;
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