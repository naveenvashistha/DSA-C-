//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        for(auto i: exp)
        {
            if(isalpha(i) || isdigit(i))
            {
                string temp(1, i);
                st.push(temp);
            }
            else
            {
                string s = st.top();
                st.pop();
                s = st.top() + i + s;
                st.pop();
                s = "(" + s + ")";
                st.push(s);
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
    cout << s.postToInfix(ss) << endl;
}
