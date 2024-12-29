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
Node* removeNthFromEnd(Node* head, int n);
Node* removeNthFromEnd1(Node* head, int n);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	head = removeNthFromEnd(head,3);
	traverse(head);
}

//brute
//time: O(n)
//space: O(1)
Node* removeNthFromEnd(Node* head, int n) {
	Node* temp = head;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	//if first node
	if(n == count)
	{
		head = head->next;
		return head;
	}
	temp = head;
	while(temp != NULL && count != n + 1)
	{
		temp = temp->next;
		count--;
	}
	//if last node
	if(n == 1)
	{
		temp->next = NULL;
		return head;
	}
	//otherwise
	temp->next = temp->next->next;
	return head;
}

//orgasmic
//time: O(N)
//space: O(1)
Node* removeNthFromEnd(Node* head, int n) {
	Node* slow = head;
	Node* fast = head;
	for(int i = 0; i < n; i++)
		fast = fast->next;
	if(fast == NULL) return head->next;
	while(fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	Node* del = slow->next;
	slow->next = slow->next->next;
	delete del;
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
