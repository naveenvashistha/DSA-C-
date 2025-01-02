#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

Node* constructDLL(vector<int>& arr);
void deleteAllOccurOfX(struct Node** head_ref, int x);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructDLL(arr);
	Node** head_ref = &head;
	deleteAllOccurOfX(head_ref, 2);
	traverse(head);
}

//orgasmic
//time: O(n)
//space: O(1)
void deleteAllOccurOfX(struct Node** head_ref, int x) {
	// Write your code here
	Node* head = *head_ref;
	//beginning node
	while(head->data == x && head != NULL)
	{
		Node* del = head;
		head = head->next;
		delete del;
	}
	if(head != NULL) head->prev = NULL;
	Node* temp = head;
	while(temp != NULL)
	{
		//in-between node
		if(temp->next != NULL && temp->data == x)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			Node* del = temp;
			temp = temp->next;
			delete del;
		}
		//last node
		else if(temp->next == NULL && temp->data == x)
		{
			temp->prev->next = NULL;
			delete temp;
		}
		else
			temp = temp->next;
	}
	*head_ref = head;
}


//time: O(n)
//space: O(1)
Node* constructDLL(vector<int>& arr) {
	// code here
	Node* head = new Node(arr[0]);
	Node* temp = head;
	for(int i = 1; i < arr.size(); i++)
	{
		//empty list
		Node* new_node = new Node(arr[i]);
		temp->next = new_node;
		new_node->prev = temp;
		temp = temp->next;
	}
	return head;
}

//time: O(n)
//space: O(1)
void traverse(Node* head)
{
	Node* temp = head;
	cout << "NULL<->";
	while(temp != NULL)
	{
		cout << temp->data << "<->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}