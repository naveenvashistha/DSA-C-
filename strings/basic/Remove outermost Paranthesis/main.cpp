#include <bits/stdc++.h>

using namespace std;

string removeOuterParentheses(string s);

//Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N.
//Find the number(between 1 to N), that is not present in the given array.

int main()
{
    string s = "()()(())";
    string ss = removeOuterParentheses(s);
    cout << ss << endl;
}

//orgasmic
//time: O(n)
//space: O(1)
string removeOuterParentheses(string s)
{
    string str = "";
    int i = 0;
    int cnt = 0;
    while(s[i] != '\0')
    {
        if(cnt == 0) cnt++;
        else if(s[i] == '(')
        {
            str += s[i];
            cnt++;
        }
        else if(s[i] == ')' && cnt > 1)
        {
            str += s[i];
            cnt--;
        }
        else cnt--;
        i++;
    }
    return str;
}