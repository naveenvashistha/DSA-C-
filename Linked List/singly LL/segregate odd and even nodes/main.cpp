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
Node* oddEvenList(Node* head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	head = oddEvenList(head);
	traverse(head);
}

//orgasmic
//time: O(n)
//space: O(1)
Node* oddEvenList(Node* head) {
	if(head == NULL || head->next == NULL) return head;
	Node* firsthead = head;
	Node* secondhead = head->next;
	Node* new_head = secondhead;
	while(firsthead->next != NULL && secondhead->next != NULL)
	{
		firsthead->next = firsthead->next->next;
		firsthead = firsthead->next;
		secondhead->next = secondhead->next->next;
		secondhead = secondhead->next;
	}
	firsthead->next = new_head;
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
