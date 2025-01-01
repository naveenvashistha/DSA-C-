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
Node* addOne(Node* head);
Node* reverseLL(Node* head);
Node* addOne1(Node* head);
int add(Node* head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {9,9,9};
	Node* head = constructLL(arr);
	head = addOne(head);
	traverse(head);
}

Node* reverseLL(Node* head)
{
	Node* prev = NULL;
	Node* temp = head;
	Node* front;
	while(temp != NULL)
	{
		front = temp->next;
		temp->next = prev;
		prev = temp;
		temp = front;
	}
	return prev;
}

//better
//time: O(3n)
//space: O(1)
Node* addOne(Node* head) {
	// Your Code here
	// return head of list after adding one
	head = reverseLL(head);
	Node* temp = head;
	int carry = 1;
	while(temp != NULL && carry != 0)
	{
		carry = (temp->data + 1) / 10;
		temp->data = (temp->data + 1) % 10;
		temp = temp->next;
	}
	head = reverseLL(head);
	if(carry == 1)
	{
		Node* new_head = new Node(1);
		new_head->next = head;
		head = new_head;
	}
	return head;
}

int add(Node* head)
{
	if(head == NULL || head->next == NULL)
	{
		int carry = (head->data + 1) / 10;
		head->data = (head->data + 1) % 10;
		return carry;
	}
	int carry = add(head->next);
	int data = head->data;
	head->data = (head->data + carry) % 10;
	carry = (data + carry) / 10;
	return carry;
}

//orgasmic (recursion)
//time: O(n)
//space: O(n)
Node* addOne1(Node* head) {
	int carry = add(head);
	if(carry == 1)
	{
		Node* new_head = new Node(1);
		new_head->next = head;
		head = new_head;
	}
	return head;
}


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
