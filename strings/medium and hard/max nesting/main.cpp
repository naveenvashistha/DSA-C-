#include <bits/stdc++.h>

using namespace std;

int maxDepth(string s);

int main()
{
    string s = "tree";
    int ss = maxDepth(s);
    cout << ss << endl;
}

int maxDepth(string s) {
    int ans =  0;
    int nesting = 0;
    for(auto i: s)
    {
        if(i == '(')
            ans++;
        else if(i == ')')
            ans--;
        if(ans > nesting)
            nesting = ans;
    }
    return nesting;
}