#include <bits/stdc++.h>

using namespace std;

bool isAnagram1(string s, string t);
bool isAnagram2(string s, string t);

int main()
{
    string s = "example", t = "fgdfdfs";
    bool ss = isAnagram1(s, t);
    cout << ss << endl;
}

//better
//time: O(nlogn)
//space: O(1)
bool isAnagram1(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

//orgasmic
//time: O(n)
//space: O(1~)
bool isAnagram2(string s, string t) {
    int ch[26] = {0};
    for(auto i: s)
    {
        ch[i - 'a']++;
    }
    for(auto i: t)
    {
        ch[i - 'a']--;
    }
    for(auto i: ch)
    {
        if(i != 0) return false;
    }
    return true;
}