#include <bits/stdc++.h>

using namespace std;

bool search_value(unordered_map<char, char> m, char c);
bool isIsomorphic(string s, string t);
bool isIsomorphic1(string s, string t);

int main()
{
    bool ss = isIsomorphic1("baba", "badc");
    cout << ss << endl;
}

bool search_value(unordered_map<char, char> m, char c)
{
    for(auto i: m)
    {
        if(c == i.second) return false;
    }
    return true;
}

//brute
//time: O(n^2)
//space: O(n)
bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;
    int size = s.length();
    unordered_map<char, char> m;
    for(int i = 0; i < size; i++)
    {
        if(m.find(s[i]) == m.end() && search_value(m, t[i])) m[s[i]] = t[i];
        else if(m[s[i]] != t[i]) return false; 
    }
    return true;
}

//orgasmic
//time: O(n)
//space: O(2*n)
bool isIsomorphic1(string s, string t)
{
    if(s.length() != t.length()) return false;
    int size = s.length();
    unordered_map<char, char> m1, m2;
    for(int i = 0; i < size; i++)
    {
        if(m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end())
        {
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        else if(m1[s[i]] != t[i] || m2[t[i]] != s[i]) return false;
    }
    return true;
}
