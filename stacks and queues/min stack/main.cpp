//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//my approach
class MinStack {
public:
    stack<int> s;
    stack<int> min;
    MinStack() {
        
    }
    void push(int val) {
        s.push(val);
        if(min.empty() || min.top() >= val) min.push(val); 
    }
    
    void pop() {
        if(!s.empty())
        {
            if(s.top() == min.top()) min.pop();
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty()) return s.top();
        return -1;
    }
    
    int getMin() {
        if(!min.empty()) return min.top();
        return -1;
    }
};

//striver's approach 1
class MinStack1 {
public:
    stack<pair<int, int>> s;
    MinStack1() {
        
    }
    void push(int val) {
        if(s.empty()) s.push({val, val});
        else
        {
            int minn = min(s.top().second, val);
            s.push({val, minn});
        } 
    }
    
    void pop() {
        if(!s.empty()) s.pop();
    }
    
    int top() {
        if(!s.empty()) return s.top().first;
        return -1;
    }
    
    int getMin() {
        if(!s.empty()) return s.top().second;
        return -1;
    }
};

//striver's approach 2 (orgasmic)
class MinStack2 {
public:
    stack<long> s;
    long min;
    MinStack2() {
        
    }
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            min = val;
        }
        else{
            if(val < min){
                s.push(2 * (long)val - min);
                min = val;
            }
            else s.push(val);
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top() < min)
            {
                min = 2 * min - s.top();
            }
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty())
        {
            if(s.top() < min) return min;
            return s.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!s.empty()) return min;
        return -1;
    }
};


int main()
{
	MinStack* obj = new MinStack();
    obj->push(2);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}
