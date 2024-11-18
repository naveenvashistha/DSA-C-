#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s);
string reverseWords1(string s);
void swapping(string &s, int m, int n);


int main()
{
    string s = "a good   example";
    string ss = reverseWords1(s);
    cout << ss << endl;
}

//better
//time: O(n)
//space: O(n)
string reverseWords1(string s)
{
    string ans = "", temp = "";
    int i = 0;
    while(s[i] == ' ') i++;
    while(s[i] != '\0')
    {
        if(s[i] == ' ')
        {
            ans = ' ' + temp + ans;
            temp = "";
            while(s[i] == ' ') i++;
        }
        else
        {
            temp += s[i];
            i++;
        }
    }
    if(s[i - 1] != ' ') 
    {
        ans = temp + ans;
        return ans;
    }
    return ans.substr(1, ans.length());
}

//orgasmic
//time: O(n)
//space: O(1)
string reverseWords(string s)
{
    int i = 0, j = 0;
    //loop to remove extra spaces from original string
    while(s[j] != '\0')
    {
        if(s[j] == ' ')
        {
            j++;
            if(i != 0 && s[i - 1] != ' ') i++;
        }
        else
        {
            char temp = s[j];
            s[j] = s[i];
            s[i] = temp;
            i++;
            j++;
        }
    }
    if(s[i - 1] == ' ') i--;
    int m = 0, n = i - 1;
    while(m <= n)
    {
        char temp = s[m];
        s[m] = s[n];
        s[n] = temp;
        m++;
        n--;
    }
    //reversing each word
    m = 0, n = 0;
    while(n < i)
    {
        if(n == i - 1 || s[n + 1] == ' ')
        {
            swapping(s, m, n);
            m = n + 2;
            n = m;
        }
        else
        {
            n++;
        }
    }
    return s;
}

void swapping(string &s, int m, int n)
{
    while(m <= n)
    {
        char temp = s[m];
        s[m] = s[n];
        s[n] = temp;
        m++;
        n--;
    }
}