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

//orgasmic
//time: O(max(m,n))
//space: O(max(m,n) + 1)
Node* addTwoNumbers(Node* l1, Node* l2) {
	Node* dummy = new Node(-1);
	Node* head = dummy;
	int carry = 0;
	while(l1 != NULL && l2 != NULL)
	{
		head->next = new Node((l1->data + l2->data + carry) % 10);
		carry = (l1->data + l2->data + carry) / 10;
		head = head->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	if(l1)
	{
		while(l1 != NULL)
		{
			head->next = new Node((l1->data + carry) % 10);
			carry = (l1->data + carry) / 10;
			head = head->next;
			l1 = l1->next;
		}
	}
	else if(l2)
	{
		while(l2 != NULL)
		{
			head->next = new Node((l2->data + carry) % 10);
			carry = (l2->data + carry) / 10;
			head = head->next;
			l2 = l2->next;
		}
	}
	if(carry != 0)
	{
		head->next = new Node(carry);
	}
	return dummy->next;
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
