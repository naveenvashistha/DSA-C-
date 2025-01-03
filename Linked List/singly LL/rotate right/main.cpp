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
int findLength(Node* head);
Node* rotateRight(Node* head, int k);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	head = rotateRight(head, 3);
	traverse(head);
}

int findLength(Node* head)
{
	Node* temp = head;
	int count = 1;
	while(temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	temp->next = head;
	return count;
}

//orgasmic
//time: O(n)
//space: O(1)
Node* rotateRight(Node* head, int k) {
	if(head == NULL || head->next == NULL || k == 0) return head;
	int count = findLength(head);
	k = k % count;
	Node* temp = head;
	while(temp != NULL)
	{
		if(count - 1 == k)
		{
			head = temp->next;
			temp->next = NULL;
			return head;
		}
		temp = temp->next;
		count--;
	}
	return NULL;
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
