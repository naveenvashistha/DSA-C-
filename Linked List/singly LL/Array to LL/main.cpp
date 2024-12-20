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

int main()
{
    vector<int> arr = {1,2,3,4,5};
	Node* head = constructLL(arr);
	while(head != NULL)
	{
		cout << head->data << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

Node* constructLL(vector<int>& arr)
{
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