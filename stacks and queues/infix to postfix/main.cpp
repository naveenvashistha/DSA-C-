//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        // Your code here
        string ans = "";
        unordered_map<char, int> op = {
          {'^', 5},
          {'*', 4},
          {'/', 4},
          {'+', 3},
          {'-', 3}
        };
        stack<char> st;
        for(auto i: s)
        {
            if(isalpha(i) || isdigit(i)) ans.push_back(i);
            else if(i == '(') st.push(i);
            else if(i == ')')
            {
                while(st.top() != '(')
                {
                    char c = st.top();
                    ans.push_back(c);
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && op[i] <= op[st.top()])
                {
                    char c = st.top();
                    ans.push_back(c);
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty())
        {
            char c = st.top();
            ans.push_back(c);
            st.pop();
        }
        return ans;
    }
};


// } Driver Code Ends
int main()
{
	Solution s;
    string ss = "a+b*(c^d-e)^(f+g*h)-i";
    cout << s.infixToPostfix(ss) << endl;
}
