#include <bits/stdc++.h>

using namespace std;

void countSubsequence(unordered_set<string> &v, int ind, string &st, string str);
string betterString(string str1, string str2);

int main()
{
    string s1 = "gfg", s2 = "ggg";
    string out = betterString(s1, s2);
    cout << out << endl;
}

void countSubsequence(unordered_set<string> &v, int ind, string &st, string str)
{
    if(ind == str.length())
    {
        v.insert(st);
        return;
    }
    st.push_back(str[ind]);
    countSubsequence(v, ind + 1, st, str);
    st.pop_back();
    countSubsequence(v, ind + 1, st, str);
}

//brute
//time: O(2^n + 2^m)
//space: O(2^n + 2^m)
string betterString(string str1, string str2) {
    // code here
    unordered_set<string> v1, v2;
    string s1 = "";
    string s2 = "";
    countSubsequence(v1, 0, s1, str1);
    countSubsequence(v2, 0, s2, str2);
    if(v1.size() >= v2.size()) return str1;
    return str2;
}