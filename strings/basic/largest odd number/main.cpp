#include <bits/stdc++.h>

using namespace std;

string largestOddNumber(string num);
string largestOddNumber1(string num); 


int main()
{
    string s = "a good   example";
    string ss = largestOddNumber(s);
    cout << ss << endl;
}

//brute
//time: O(n^2)
//space: O(1)
string largestOddNumber(string num) {
    int length = num.length();
    long long odd_num = 0;
    for(int i = 0; i < length; i++)
    {
        string s = "";
        for(int j = i; j < length; j++)
        {
            s = s + num[j];
            long long number = stoi(s);
            if(number % 2 != 0 && number > odd_num)
            {
                odd_num = number;
            }
        }
    }
    return odd_num == 0 ? "" : to_string(odd_num);
}

//orgasmic approach
//start from end and return the string when u found the first odd digit, otherwise move to left
//time: O(n)
//spacE: O(1)
string largestOddNumber1(string num)
{
    int length = num.length();
    for(int i = length; i >= 0; i--)
    {
        int digit = num[i] - '0';
        if(digit % 2 != 0)
             return num.substr(0, i);
    }
    return "";
} 