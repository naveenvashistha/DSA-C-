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
Node* sortList(Node* head);
Node* sortList1(Node* head);
Node* mergeList(Node* lefthead, Node* righthead);
Node* findMiddle(Node* head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1};
	Node* head = constructLL(arr);
	head = sortList(head);
	traverse(head);
}

//brute
//time: O(n^2)
//space: O(1)
Node* sortList(Node* head) {
	if(head == NULL || head->next == NULL) return head;
	bool swapped = true;
	while(swapped == true)
	{
		Node* temp = head;
		swapped = false;
		while(temp->next != NULL)
		{
			if(temp->data > temp->next->data)
			{
				swap(temp->data, temp->next->data);
				swapped = true;
			}
			temp = temp->next;
		}
	}
	return head;
}

Node* findMiddle(Node* head)
{
	Node* slow = head;
	Node* fast = head->next;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
} 

Node* mergeList(Node* lefthead, Node* righthead)
{
	Node* dummy = new Node(-1);
	Node* temp = dummy;
	while(lefthead != NULL && righthead != NULL)
	{
		if(lefthead->data < righthead->data)
		{
			temp->next = lefthead;
			temp = lefthead;
			lefthead = lefthead->next;
		}
		else
		{
			temp->next = righthead;
			temp = righthead;
			righthead = righthead->next;
		}
	}
	if(lefthead) temp->next = lefthead;
	else temp->next = righthead;
	return dummy->next;
}

//orgasmic
//time: O(logn*(n+n/2))
//space: O(1)
Node* sortList1(Node* head) {
	if(head == NULL || head->next == NULL) return head;
	Node* middle = findMiddle(head);
	Node* lefthead = head;
	Node* righthead = middle->next;
	middle->next = NULL;
	lefthead = sortList1(lefthead);
	righthead = sortList1(righthead);
	Node* h = mergeList(lefthead, righthead);
	return h;
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
