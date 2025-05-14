#include <bits/stdc++.h>
using namespace std;

//push is O(n) here but pop is O(1)
class MyQueue1 {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue1() {
        
    }
    
    void push(int x) {
        while(!s1.empty())
        {
            int y = s1.top();
            s1.pop();
            s2.push(y);
        }
        s2.push(x);
        while(!s2.empty())
        {
            int y = s2.top();
            s2.pop();
            s1.push(y);
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty()) return true;
        return false;
    }
};

//push is O(1) but pop is O(n)
class MyQueue2 {
public:
    stack<int> s1;
    stack<int> s2;
    int front;
    MyQueue2() {
    }
    
    void push(int x) {
        if(s1.empty())
        {
            front = x;
        }
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty())
        {
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }
        int p = s2.top();
        s2.pop();
        if(!s2.empty()) front = s2.top();
        while(!s2.empty())
        {
            int x = s2.top();
            s2.pop();
            s1.push(x);
        }
        return p;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        if(s1.empty()) return true;
        return false;
    }
};


int main()
{
	MyQueue1 q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
}
