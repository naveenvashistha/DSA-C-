#include <bits/stdc++.h>

using namespace std;

void Reverse(stack<int> &St);
void sorty(stack<int> &s, int x);

int main()
{
    stack<int> s;
    s.push(3); 
    s.push(6);
    s.push(2);
    s.push(8);
    Reverse(s);
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void sorty(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int p = s.top();
    s.pop();
    sorty(s, x);
    
    s.push(p);
}

//orgasmic
//time: O(n^2)
//space: O(1)
void Reverse(stack<int> &St)
{
    if(St.empty()) return;
    
    int x = St.top();
    
    St.pop();
    
    Reverse(St);
    
    //this part will run when recursion starts backtracking on encountring empty stack

    sorty(St, x);
}