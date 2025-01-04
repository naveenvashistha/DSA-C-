#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
	Node* bottom;
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
		bottom = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
		this->bottom = NULL;
    }
};

Node *flatten(Node *root);
Node *flatten1(Node *root);
Node* getLastChild(Node* head);
Node* findMiddle(Node* head);
Node* merge(Node* lefthead, Node* righthead);
Node* sortLL(Node* head);
void traverse(Node* head);

int main()
{
	//construct linked list first manually
	Node* head = new Node(3);
	head->next = new Node(9);
	head->bottom = new Node(4);
	head->next->bottom = new Node(10);
	head = flatten(head);
	traverse(head);
}

Node* getLastChild(Node* head)
{
	while(head->bottom != NULL)
		head = head->bottom;
	return head;
}

Node* findMiddle(Node* head)
{
	Node* slow = head;
	Node* fast = head->bottom;
	while(fast->bottom != NULL && fast->bottom->bottom != NULL)
	{
		slow = slow->bottom;
		fast = fast->bottom->bottom;
	}
	Node* h = slow->bottom;
	slow->bottom = NULL;
	return h;
}

Node* merge(Node* lefthead, Node* righthead)
{
	Node* dummy = new Node(-1);
	Node* temp = dummy;
	while(lefthead != NULL && righthead != NULL)
	{
		if(lefthead->data < righthead->data)
		{
			temp->bottom = lefthead;
			temp = lefthead;
			lefthead = lefthead->bottom;
		}
		else
		{
			temp->bottom = righthead;
			temp = righthead;
			righthead = righthead->bottom;
		}
	}
	if(lefthead)
		temp->bottom = lefthead;
	else
		temp->bottom = righthead;
	return dummy->bottom;
}

Node* sortLL(Node* head)
{
	if(head == NULL || head->bottom == NULL) return head;
	Node* lefthead = head;
	Node* righthead = findMiddle(head);
	lefthead = sortLL(lefthead);
	righthead = sortLL(righthead);
	Node* new_head = merge(lefthead, righthead);
	return new_head;
}

// Function which returns the  root of the flattened linked list.
//better
//time: O(n*m + n*mlog(n*m))
//space: O(logn*m) 
Node *flatten(Node *root) {
	// Your code here
	Node* temp = root;
	while(temp != NULL)
	{
		Node* child = getLastChild(temp);
		child->bottom = temp->next;
		temp = temp->next;
	}
	root = sortLL(root);
	return root;
}

//orgasmic
//time: O(n*m*n)
//space: O(1)
Node *flatten1(Node *root) {
	// Your code here
	Node* temp1 = root;
	Node* temp2 = root->next;
	while(temp2 != NULL)
	{
		temp1 = merge(temp1, temp2);
		temp2 = temp2->next;
	}
	return temp1;
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
