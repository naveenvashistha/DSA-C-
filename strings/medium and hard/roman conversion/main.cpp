#include <bits/stdc++.h>

using namespace std;

int romanToInt1(string s);
int romanToInt2(string s);  

int main()
{
    string s = "tree";
    int ss = romanToInt1(s);
    cout << ss << endl;
}

//brute
//time: O(n)
//space: O(1)
int romanToInt1(string s) {
    int value = 0;
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == 'I')
        {
            if(s[i + 1] == 'V')
            {
                value += 4;
                i++;
            }
            else if(s[i + 1] == 'X')
            {
                value += 9;
                i++;
            }
            else value += 1;
        }
        else if(s[i] == 'X')
        {
            if(s[i + 1] == 'L')
            {
                value += 40;
                i++;
            }
            else if(s[i + 1] == 'C')
            {
                value += 90;
                i++;
            }
            else value += 10;
        }
        else if(s[i] == 'C')
        {
            if(s[i + 1] == 'D')
            {
                value += 400;
                i++;
            }
            else if(s[i + 1] == 'M')
            {
                value += 900;
                i++;
            }
            else value += 100;
        }
        else if(s[i] == 'M') value += 1000;
        else if(s[i] == 'L') value += 50;
        else if(s[i] == 'V') value += 5;
        else if(s[i] == 'D') value += 500;
        i++;
    }
    return value;
}

//orgasmic
//time: O(n)
//space: O(1)
int romanToInt2(string s)
{
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int length = s.length();
    int value = 0;

    for(int i = 0; i < length - 1; i++)
    {
        if(m[s[i]] < m[s[i + 1]]) value -= m[s[i]];
        else value += m[s[i]];
    }
    value += m[s[length - 1]];
    return value;
}