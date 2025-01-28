//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
bool isValid(string s) {
    stack<int> st;
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if(st.empty()) return false;
            if(s[i] == ')')
            {
                if(st.top() != '(') return false;
            }
            else if(s[i] == '}')
            {
                if(st.top() != '{') return false;
            }
            else
            {
                if(st.top() != '[') return false;
            }
            st.pop();
        }
        i++;
    }
    if(st.empty()) return true;
    return false;
}

int main()
{
	cout << isValid("(())") << endl;
}
