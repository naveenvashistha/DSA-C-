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
    string infixToPrefix(string& s) {
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
        for(int i = s.length(); i >= 0; i--)
        {
            if(isalpha(s[i]) || isdigit(s[i])) ans = s[i] + ans;
            else if(s[i] == ')') st.push(s[i]);
            else if(s[i] == '(')
            {
                while(st.top() != ')')
                {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && op[s[i]] < op[st.top()])
                {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};


// } Driver Code Ends
int main()
{
	Solution s;
    string ss = "a+b";
    cout << s.infixToPrefix(ss) << endl;
}
