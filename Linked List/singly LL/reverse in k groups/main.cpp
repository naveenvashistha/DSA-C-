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
Node* reverseKGroup(Node* head, int k);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	head = reverseKGroup(head, 3);
	traverse(head);
}

int findLength(Node* head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

//orgasmic
//time: O(n)
//space: O(1)
Node* reverseKGroup(Node* head, int k) {
	if(head == NULL || head->next == NULL) return head;
	int count = findLength(head);
	int i;
	Node* temp = head;
	Node* front;
	Node* t;
	Node* old_t = NULL;
	while(count >= k)
	{
		i = 1;
		t = temp;
		Node* prev = NULL;
		while(i <= k)
		{
			front = temp->next;
			temp->next = prev;
			prev = temp;
			temp = front;
			i++;
		}
		if(t == head) head = prev;
		t->next = temp;
		if(old_t != NULL) old_t->next = prev;
		old_t = t;
		count = count - k;
	}
	return head;
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
