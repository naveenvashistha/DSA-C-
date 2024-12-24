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
//time: O(n) average case O(n*logn) worst case
//space: O(n)
int countNodesinLoop1(Node *head) {
	unordered_map<Node*, int> addr;
	int count = 0;
	while(head != NULL)
	{
		if(addr.find(head) != addr.end()) return count - addr[head];
		addr[head] = count;
		head = head->next;
		count++;
	}
	return 0;
}

//orgasmic
//time: O(n)
//space: O(1)
int countNodesinLoop(Node *head) {
	Node* hare = head;
	Node* tortoise = head;
	while(hare != NULL && hare->next != NULL)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
		if(hare == tortoise)
		{
			tortoise = tortoise->next;
			int count = 1;
			while(tortoise != hare)
			{
				tortoise = tortoise->next;
				count++;
			}
			return count;
		}
	}
	return 0;
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
