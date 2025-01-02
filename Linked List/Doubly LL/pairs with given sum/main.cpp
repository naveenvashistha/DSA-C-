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
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructDLL(arr);
	vector<pair<int, int>> v = findPairsWithGivenSum(head, 2);
	for(auto i: v)
		cout << i.first << "," << i.second << endl;
}

//time: O(2n)
//space: O(1)
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
	// code here
	Node* temp = head;
	vector<pair<int, int>> v;
	while(temp->next != NULL)
		temp = temp->next;
	while(head != temp)
	{
		if(head->data + temp->data > target)
			temp = temp->prev;
		else if(head->data + temp->data < target)
			head = head->next;
		else
		{
			v.push_back({head->data, temp->data});
			head = head->next;
		}
	}
	return v;
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