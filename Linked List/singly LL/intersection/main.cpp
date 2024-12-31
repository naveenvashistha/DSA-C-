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
Node *getIntersectionNode(Node *headA, Node *headB);
Node *getIntersectionNode1(Node *headA, Node *headB);
Node *getIntersectionNode2(Node *headA, Node *headB);
Node *getIntersectionNode3(Node *headA, Node *headB);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1};
	vector<int> arr1 = {1,2, 4};
	Node* headA = constructLL(arr);
	Node* headB = constructLL(arr1);
	Node* intersection = getIntersectionNode1(headA, headB);
	cout << intersection->data << endl;
}

//brute
//time: O(n^2)
//space: O(1)
Node *getIntersectionNode(Node *headA, Node *headB) {
	while(headA != NULL)
	{
		Node* temp = headB;
		while(temp != NULL)
		{
			if(temp == headA) return temp;
			temp = temp->next;
		}
		headA = headA->next;
	}
	return NULL;
}

//better
//time: O(2n)
//space: O(n)
Node *getIntersectionNode1(Node *headA, Node *headB) {
	unordered_set<Node*> addr;
	while(headA != NULL)
	{
		addr.insert(headA);
		headA = headA->next;
	}
	while(headB != NULL)
	{
		if(addr.find(headB) != addr.end()) return headB;
		headB = headB->next;
	}
	return NULL;
}

//much better
//time: O(n)
//space: O(1)
Node *getIntersectionNode2(Node *headA, Node *headB) {
	Node* temp1 = headA;
	Node* temp2 = headB;
	int count1 = 0, count2 = 0;
	while(temp1 != NULL)
	{
		count1++;
		temp1 = temp1->next;
	}
	while(temp2 != NULL)
	{
		count2++;
		temp2 = temp2->next;
	}
	if(count1 > count2)
	{
		for(int i = 0; i < count1 - count2; i++)
		{
			headA = headA->next;
		}
	}
	else
	{
		for(int i = 0; i < count2 - count1; i++)
		{
			headB = headB->next;
		}
	}
	while(headA != NULL)
	{
		if(headA == headB) return headA;
		headA = headA->next;
		headB = headB->next;
	}
	return NULL;
}

//orgasmic
//time: O(n)
//space: O(1)
Node *getIntersectionNode3(Node *headA, Node *headB) {
	Node* temp1 = headA;
	Node* temp2 = headB;
	while(temp1 != temp2)
	{
		temp1 = temp1 == NULL ? headB : temp1->next;
		temp2 = temp2 == NULL ? headA : temp2->next;
	}
	return temp1;
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
