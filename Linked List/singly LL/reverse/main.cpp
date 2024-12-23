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
Node* reverse1(Node* head);
Node* reverse2(Node* head);
Node* reverse3(Node* head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	head = reverse2(head);
	traverse(head);
}

//brute
//time: O(2n)
//space: O(n)
Node* reverse1(Node* head) {
	stack<int> st;
	Node* temp = head;
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
Node* reverse2(Node* head) {
	Node* temp = head;
	Node* prev = NULL;
	Node* front;
	while(temp != NULL)
	{
		front = temp->next;
		temp->next = prev;
		prev = temp;
		temp = front;
	}
	return prev;
}

//orgasmic (recursion)
//time: O(n)
//space: O(n) (due to function storing in stack during recursion calls)
Node* reverse3(Node* head) {
	if(head == NULL || head->next == NULL) return head;
	Node* new_head = reverse3(head->next);
	Node* front  = head->next;
	front->next =  head;
	head->next =  NULL;
	return new_head;
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
