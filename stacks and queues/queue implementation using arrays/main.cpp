#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    int *arr;
    int front;
    int rear;

public :
    MyQueue(){
        arr = new int[16];
        front=-1;
        rear=-1;
    }
    MyQueue(int s)
    {
        arr = new int[s];
        front=-1;
        rear=-1;
    }
    void push(int);
    int pop();
    int getFront();
    int size();
};

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    // Your Code
    int size = sizeof(arr) / sizeof(int);
    if(front == -1)
    {
        front++;
        rear++;
        arr[rear] = x;
    }
    else if(front == (rear + 1) % size)
    {
        cout << "overflow" << endl;
    }
    else
    {
        rear = (rear + 1) % size;
        arr[rear] = x;
    }
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    // Your Code
    int size = sizeof(arr) / sizeof(int);
    if(front == -1)
        cout << "underflow" << endl;
    else if(front == rear)
    {
        int x = arr[front];
        front = -1;
        rear = -1;
        return x;
    }
    else{
        int x = arr[front];
        front = (front + 1) % size;
        return x;
    } 
}

int MyQueue :: getFront()
{
    if(front == -1)
    {
        cout << "underflow";
        return -1;
    }
    return arr[front];
}

int MyQueue :: size()
{
    int size = sizeof(arr) / sizeof(int);
    if(front == -1) return 0;   
    return ((size - front + rear) % size) + 1;
}

int main()
{
	MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
}
