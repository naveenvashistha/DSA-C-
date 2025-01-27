#include <bits/stdc++.h>
using namespace std;

//using two queues
class MyStack1 {
    queue<int> q1;
    queue<int> q2;
    public:
        MyStack1() {
        }
        
        void push(int x) {
            if(q1.empty())
            {
                q1.push(x);
                return;
            }
            while(!q1.empty())
            {
                int y = q1.front();
                q1.pop();
                q2.push(y);
            }
            q1.push(x);
            while(!q2.empty())
            {
                int y = q2.front();
                q2.pop();
                q1.push(y);
            }
        }
        
        int pop() {
            int x = q1.front();
            q1.pop();
            return x;
        }
        
        int top() {
            return q1.front();
        }
        
        bool empty() {
            if(q1.empty()) return true;
            return false;
        }
};

//using single queue (preferrable)
class MyStack2 {
    queue<int> q1;
    
    public:
        MyStack2() {
        }
        
        void push(int x) {
            int size = q1.size();
            q1.push(x);
            for(int i = 0; i < size; i++)
            {
                q1.push(q1.front());
                q1.pop();
            }
        }
        
        int pop() {
            int x = q1.front();
            q1.pop();
            return x;
        }
        
        int top() {
            return q1.front();
        }
        
        bool empty() {
            if(q1.empty()) return true;
            return false;
        }
};


int main()
{
	MyStack1* obj = new MyStack1();
    obj->push(12);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
}
