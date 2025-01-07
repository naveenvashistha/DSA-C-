#include <bits/stdc++.h>

using namespace std;

void sort(stack<int> &s);

int main()
{
    stack<int> s;
    s.push(3); 
    s.push(6);
    s.push(2);
    s.push(8);
    sort(s);
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void sort(stack<int> &s)
{
   //Your code here
   if(s.empty()) return;
   int x = s.top();
   s.pop();
   sort(s);
   
   stack<int> temp;
   //move all elements greater than x into temp stack
   while(!s.empty() && s.top() > x)
   {
       temp.push(s.top());
       s.pop();
   }
   
   s.push(x);
   
   //move back all the elements from temp to s
   while(!temp.empty())
   {
       s.push(temp.top());
       temp.pop();
   }
}