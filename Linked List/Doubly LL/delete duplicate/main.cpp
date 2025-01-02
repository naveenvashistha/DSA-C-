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
Node * removeDuplicates(struct Node *head);
void traverse(Node* head);

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = constructDLL(arr);
	head = removeDuplicates(head);
	traverse(head);
}

//orgasmic
//time: O(n)
//space: O(1)
Node * removeDuplicates(Node *head)
{
	// Your code here
	if(head == NULL || head->next == NULL) return head;
	Node* first = head;
	Node* sec = head->next;
	while(sec != NULL)
	{
		if(first->data == sec->data)
		{
			//in between
			if(sec->next != NULL)
			{
				sec->next->prev = sec->prev;
				sec->prev->next = sec->next;
				Node* del = sec;
				sec = sec->next;
				delete del;
			}
			//end
			else
			{
				sec->prev->next = NULL;
				Node* del = sec;
				sec = sec->next;
				delete del;
			}
		}
		else
		{
			first = first->next;
			sec = sec->next;
		}
	}
	return head;
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