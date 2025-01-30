
#include <bits/stdc++.h>
using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
class Solution {
  public:
    string preToPost(string s) {
        stack<string> st;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(isalnum(s[i]))
            {
                string temp(1, s[i]);
                st.push(temp);
            }
            else
            {
                string ss = st.top();
                st.pop();
                ss += st.top();
                st.pop();
                st.push(ss + s[i]);
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
    cout << s.preToPost(ss) << endl;
}
