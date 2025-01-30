
#include <bits/stdc++.h>
using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        stack<string> st;
        for(auto i: s)
        {
            if(isalnum(i))
            {
                string temp(1, i);
                st.push(temp);
            }
            else
            {
                string ss = st.top();
                st.pop();
                ss = st.top() + ss;
                st.pop();
                st.push(i + ss);
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
    cout << s.postToPre(ss) << endl;
}
