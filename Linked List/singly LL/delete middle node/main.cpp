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
Node* deleteMiddle(Node* head);
Node* deleteMiddle1(Node* head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1};
	Node* head = constructLL(arr);
	head = deleteMiddle(head);
	traverse(head);
}

//brute
//time: O(n)
//space: O(1)
Node* deleteMiddle(Node* head) {
	Node* temp = head;
	int count = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	int middle = count / 2;
	temp = head;
	if(middle == 0)
	{
		Node* del = head;
		head = head->next;
		delete del;
		return head;
	}
	int i = 0;
	while(temp != NULL && i != middle - 1)
	{
		temp = temp->next;
		i++;
	}
	Node* del = temp->next;
	temp->next = temp->next->next;
	delete del;
	return head;
}

//orgasmic
//time: O(n)
//space: O(1)	
Node* deleteMiddle(Node* head) {
	if(head->next == NULL)
	{
		delete head;
		return NULL;
	}
	Node* slow = head;
	Node* fast = head->next->next;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
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
