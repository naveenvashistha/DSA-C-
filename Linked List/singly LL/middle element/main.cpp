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
Node* middleNode1(Node* head);
Node* middleNode2(Node* head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	Node* middle = middleNode2(head);
	cout << middle->data << endl;
}

//brute
//time: O(2n)
//space: O(1)
Node* middleNode1(Node* head) {
	Node* temp = head;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	int mid = count / 2 + 1;
	int i = 1;
	temp = head;
	while(i != mid)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

//orgasmic (tortoise and hare algorithm)
//time: O(n)
//space: O(1)
Node* middleNode2(Node* head)
{
	Node* hare = head;
	Node* tortoise = head;
	while(hare != NULL && hare->next != NULL)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
	}
	return tortoise;
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
