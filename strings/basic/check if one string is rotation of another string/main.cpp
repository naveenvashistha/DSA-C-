#include <bits/stdc++.h>

using namespace std;

bool rotateString1(string s, string goal);


int main()
{
    string s = "abcd", t = "bcda";
    bool ss = rotateString1(s, t);
    cout << ss << endl;
}

//brute
//time: O(n^2)
//space: O(1)
bool rotateString1(string s, string goal) {
    int length = s.length();
    int length1 = goal.length();
    int j;
    if(length != length1) return false;
    for(int i = 1; i <= length; i++)
    {
        for(j = 0; j < length; j++)
        {
            if(s[j] != goal[(j + i) % length])
                break;
        }
        if(j == length) return true;
    }
    return false;
}

//The key insight is that when you concatenate a string with itself (s + s), it contains all possible rotations of the original string.
//orgasmic solution
//time: O(n)
//space: O(1)
bool rotateString2(string s, string goal)
{
    int len1 = s.length();
    int len2 = goal.length();
    if(len1 != len2) return false;
    string t = s + s;
    int i = 0;
    while(i + len2 < 2 * len1)
    {
        if(t.substr(i, len2) == goal) return true;
        i++;
    }
    return false;
} 