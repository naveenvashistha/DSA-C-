//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        stack<string> st;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                string temp(1, s[i]);
                st.push(temp);
            }
            else
            {
                string ss = st.top();
                st.pop();
                ss = "(" + ss + s[i] + st.top() + ")";
                st.pop();
                st.push(ss);
            }
        }
        return st.top();
    }
};
// } Driver Code Ends
int main()
{
	Solution s;
    string ss = "ab*c+";
    cout << s.preToInfix(ss) << endl;
}
