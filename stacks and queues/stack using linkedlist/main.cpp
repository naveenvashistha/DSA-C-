//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};


// } Driver Code Ends
class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode *new_node = new StackNode(x);
        new_node->next = top;
        top = new_node;
    }

    int pop() {
        // code here
        if(top == NULL) return -1;
        StackNode* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return x;
        
    }

    MyStack() { top = NULL; }
};


int main()
{
	MyStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
}
