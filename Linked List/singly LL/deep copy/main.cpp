#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
	Node* random;
    // Default constructor
    Node()
    {
        val = 0;
        next = NULL;
		random = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
		this->random = NULL;
    }
};

Node* copyRandomList(Node* head);
Node* copyRandomList1(Node* head);

int main()
{
	//construct linked list first manually
	Node* head = new Node(3);
	head->next = new Node(9);
	head->next->next = new Node(11);
	head->next->random = head->next;
	head = copyRandomList(head);
}

//brute
//time: O(2n)
//space: O(n)
Node* copyRandomList(Node* head) {
	Node* temp = head;
	Node* dummy = new Node(-1);
	Node* point = dummy;
	unordered_map<Node*, Node*> m;
	while(temp != NULL)
	{
		Node* new_node = new Node(temp->val);
		point->next = new_node;
		point = new_node;
		m[temp] = new_node;
		temp = temp->next;
	}
	temp = head;
	Node* new_head = dummy->next;
	while(temp != NULL)
	{
		new_head->random = m[temp->random];
		temp = temp->next;
		new_head = new_head->next;
	}
	return dummy->next;
}

//orgasmic
//time: O(3n)
//space: O(1)
Node* copyRandomList1(Node* head) {
	if(head == NULL) return NULL;
	Node* temp = head;
	while(temp != NULL)
	{
		Node* new_node = new Node(temp->val);
		Node* s = temp->next;
		temp->next = new_node;
		new_node->next = s;
		temp = temp->next->next;
	}
	temp = head;
	Node* new_head = temp->next;
	while(temp != NULL)
	{
		Node* copied = temp->next;
		if (temp->random != NULL) copied->random = temp->random->next;
		temp = temp->next->next;
	}
	temp = head;
	while(temp != NULL)
	{
		Node* copied = temp->next;
		Node* s = copied->next;
		if(copied->next != NULL) copied->next = copied->next->next;
		temp->next = s;
		temp = s;
	}
	return new_head;
}