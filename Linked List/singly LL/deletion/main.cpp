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
Node* deleteAtBegin(Node* head);
Node* deleteAtEnd(Node* head);
Node* deleteAtPos(Node* head, int pos);
Node* deleteByVal(Node* head, int val);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	head = deleteByVal(head, 7);
	traverse(head);
}

//time: O(1)
//space: O(1)
Node* deleteAtBegin(Node* head)
{
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
} 

//time: O(n)
//space: O(1)
Node* deleteAtEnd(Node* head)
{
	Node* temp = head;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	Node* tempo = temp->next;
	temp->next = NULL;
	delete tempo;
	return head;
}

//time: O(n)
//space: O(1)
Node* deleteAtPos(Node* head, int pos)
{
	if(pos == 1) return deleteAtBegin(head);
	int i = 1;
	Node* temp = head;
	while(temp != NULL && i != pos - 1)
	{
		temp = temp->next;
		i++;
	}
	if(temp == NULL || temp->next == NULL)
	{
		cout << "out of bounds" << endl;
		return head;
	}
	delete temp->next;
	temp->next = temp->next->next;
	return head;
}

//time: O(n)
//space: O(1)
Node* deleteByVal(Node* head, int val)
{
	if(head->data == val) return deleteAtBegin(head);
	Node* temp = head;
	while(temp->next != NULL && temp->next->data != val)
		temp = temp->next;
	if(temp->next == NULL)
	{
		cout << "value not found" << endl;
		return head;
	}
	delete temp->next;
	temp->next = temp->next->next;
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