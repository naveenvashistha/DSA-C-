//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};


//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        if(front == NULL)
        {
            QueueNode *new_node = new QueueNode(x);
            front = new_node;
            rear = new_node;
        }
        else{
            QueueNode *new_node = new QueueNode(x);
            rear->next = new_node;
            rear = new_node;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    // Your Code
    if(front == NULL)
    {
        return -1;   
    }
    if(front == rear)
    {
        rear = NULL;
    }
    int x = front->data;
    QueueNode* temp = front;
    front = front->next;
    delete temp;
    return x;    
}


int main()
{
	MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
}
