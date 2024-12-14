#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s);

int main()
{
    string s = "  +  413";
    int ss = myAtoi(s);
    cout << ss << endl;
}

//orgasmic
//time:O(n)
//space: O(1)
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

    //recording value
    while(s[i] >= '0' && s[i] <= '9')
    {
        ans = ans * 10 + (s[i] - '0');
        if(isNegative == true)
        {
            if(-ans <= INT_MIN) return INT_MIN;
        }
        else if(ans >= INT_MAX) return INT_MAX;
        i++;
    }
    if(isNegative == true) return -(int)ans;
    return (int)ans;
}
