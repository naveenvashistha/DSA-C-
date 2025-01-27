#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
    int size();
    int getTop();
};

void MyStack ::push(int x) {
    // Your Code
    int size  = sizeof(arr) / sizeof(int);
    if(top == size - 1)
    {
        cout << "stack is full" << endl;
        return;
    }
    arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if(top == -1) return -1;
    return arr[top--];
}

int MyStack :: size()
{
    return top + 1;
}

int MyStack :: getTop()
{
    if(top == -1)
    {
        cout << "stack is empty" << endl;
        return 0; 
    }
    return arr[top];
}


int main()
{
	MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout << s.getTop() << endl;
    cout << s.size() << endl;
}
