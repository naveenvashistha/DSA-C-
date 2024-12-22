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
Node* reverseDLL(Node* head);
Node* reverseDLL1(Node* head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructDLL(arr);
	head = reverseDLL1(head);
	traverse(head);
}

//brute
//time: O(n)
//space: O(n)
Node* reverseDLL1(Node* head)
{
	// Your code here
	stack<int> st;
	Node* temp= head;
	while(temp != NULL)
	{
		st.push(temp->data);
		temp = temp->next;
	}
	temp = head;
	while(temp != NULL)
	{
		temp->data = st.top();
		st.pop();
		temp = temp->next;
	}
	return head;
}

//orgasmic
//time: O(n)
//space: O(1)
Node* reverseDLL(Node* head)
{
	// Your code here
	while(head->next != NULL)
	{
		Node* tempo = head->next;
		head->next = head->prev;
		head->prev = tempo;
		head = tempo;
	}
	Node* tempo = head->next;
	head->next = head->prev;
	head->prev = tempo;
	return head;
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