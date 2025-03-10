#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(1)
bool checkValidString(string s) {
    int leftMin = 0; //minimum left ("(") open parenthesis
    int leftMax = 0; //maximum left ("(") open parenthesis
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            leftMin++;
            leftMax++;
        }
        else if(s[i] == ')')
        {
            if(leftMin > 0) leftMin--;
            leftMax--;
            if(leftMax < 0) return false;
        }
        else
        {
            if(leftMin > 0) leftMin--;
            leftMax++;
        }
    }
    return leftMin == 0;
}


int main()
{
}

