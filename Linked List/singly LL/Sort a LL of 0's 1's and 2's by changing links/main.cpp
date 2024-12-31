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
Node* segregate(Node* head);
Node* segregate1(Node* head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1};
	Node* head = constructLL(arr);
	head = segregate(head);
	traverse(head);
}

//brute
//time: O(2n)
//space: O(1)
Node* segregate(Node* head) {
	// Add code here
	int zeros = 0, ones = 0, twos = 0;
	Node* temp = head;
	while(temp != NULL)
	{
		if(temp->data == 0) zeros++;
		else if(temp->data == 1) ones++;
		else twos++;
		temp = temp->next;
	}
	temp = head;
	for(int i = 0; i < zeros; i++)
	{
		temp->data = 0;
		temp = temp->next;
	}
	for(int i = 0; i < ones; i++)
	{
		temp->data = 1;
		temp = temp->next;
	}
	for(int i = 0; i < twos; i++)
	{
		temp->data = 2;
		temp = temp->next;
	}
	return head;
}

//orgasmic
//time: O(n)
//space: O(1)
Node* segregate1(Node* head) {
	// Add code here
	Node* temp = head;
	Node* dummy_zero = new Node(-1);
	Node* temp_zero = dummy_zero;
	Node* dummy_one = new Node(-1);
	Node* temp_one = dummy_one;
	Node* dummy_two = new Node(-1);
	Node* temp_two = dummy_two;
	while(temp != NULL)
	{
		if(temp->data == 0)
		{
			temp_zero->next = temp;
			temp_zero = temp;
		}
		else if(temp->data == 1)
		{
			temp_one->next = temp;
			temp_one = temp;
		}
		else
		{
			temp_two->next = temp;
			temp_two = temp;
		}
		temp = temp->next;
	}
	temp_zero->next = dummy_one->next ? dummy_one->next : dummy_two->next;
	temp_one->next = dummy_two->next;
	temp_two->next = NULL;
	return dummy_zero->next;
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
