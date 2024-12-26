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
Node* hasCycle(Node *head);
int countNodesinLoop(Node *head);
int countNodesinLoop1(Node *head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	cout << countNodesinLoop(head) << endl;
}

//brute
//time: O(2n)
//s[ace: O(n)
bool isPalindrome(Node* head) {
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
		if(temp->data != st.top()) return false;
		st.pop();
		temp = temp->next;
	}
	return true;
}

//orgasmic
//divide linkedlist in two halves and reverse the second half and then compare with first half
//if every value is equal then its palindrome otherwise not
//time: O(2n)
//space: O(1)
bool isPalindrome(Node* head) {
	Node* slow = head;
	Node* fast = head;
	if(head == NULL || head->next == NULL) return true;
	while(fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* new_head = reversed(slow->next);
	Node* temp1 = new_head;
	Node* temp = head;
	while(temp1 != NULL)
	{
		if(temp->data != temp1->data)
		{
			Node* node = reversed(new_head);
			return false;
		}
		temp1 = temp1->next;
		temp = temp->next;
	}
	Node* node = reversed(new_head);
	return true;
}

Node* reversed(Node* head)
{
	Node* front;
	Node* prev = NULL;
	while(head != NULL)
	{
		front = head->next;
		head->next = prev;
		prev = head;
		head = front;
	}
	return prev;
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
