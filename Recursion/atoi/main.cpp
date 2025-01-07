#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s);
long long atoi(string s, int i, long long ans, bool isNegative);

int main()
{
    string s = "  +  413";
    int ss = myAtoi(s);
    cout << ss << endl;
}

long long atoi(string s, int i, long long ans, bool isNegative)
{
    if(s[i] >= '0' && s[i] <= '9')
    {
        ans = ans * 10 + (s[i] - '0');
        if(isNegative == true)
        {
            if(-ans <= INT_MIN)
                return INT_MIN;
        }
        else if(ans >= INT_MAX) return INT_MAX;
        return atoi(s, i + 1, ans, isNegative);
    }
    else
    {
        if(isNegative == true) return -ans;
        return ans;
    }
}

//orgasmic
//time: O(n)
//space: O(n)
int myAtoi(string s) {
    int i = 0;
    long long ans = 0;
    bool isNegative = false;

    //handling leading white space
    while(s[i] == ' ') i++;

    //handling sign
    if(s[i] == '-')
    {
        isNegative = true;
        i++;
    }
    else if(s[i] == '+') i++;

    ans = atoi(s, i, ans, isNegative);
    return (int)ans;
}