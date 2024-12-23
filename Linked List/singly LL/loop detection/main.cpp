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
bool hasCycle(Node *head);
bool hasCycle1(Node *head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructLL(arr);
	cout << hasCycle(head) << endl;
}

//brute
//time: O(n) average, O(2*n*logn) worst case
//space: O(n)
bool hasCycle(Node *head) {
	unordered_set<Node*> addr;
	while(head != NULL)
	{
		auto result = addr.insert(head);
		if(!result.second) return true;
		head = head->next;
	}
	return false;
}

//orgasmic (tortoise hare algo)
//time: O(n)
//space: O(1)
bool hasCycle(Node *head) {
	Node* hare = head;
	Node* tortoise = head;
	while(hare != NULL && hare->next != NULL)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
		if(hare == tortoise) return true;
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
