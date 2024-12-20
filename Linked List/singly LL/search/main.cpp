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
bool searchKey(struct Node* head, int key);

void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	cout << searchKey(head, 3) << endl;
}

//time: O(n)
//space: O(1)
bool searchKey(struct Node* head, int key) {
	// Code here
	while(head != NULL)
	{
		if(head->data == key) return true;
		head = head->next;
	}
	return false;
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
