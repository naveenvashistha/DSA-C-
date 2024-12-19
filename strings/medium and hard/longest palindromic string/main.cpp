#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s); 
string longestPalindrome1(string s); 

int main()
{
    string s = "ababababababababababababababababa";
    string ss = longestPalindrome1(s);
    cout << ss << endl;
}

//brute
//time: O(n^3) because string comparison takes O(n) 
//space: O(1)
string longestPalindrome(string s) {
    int length = s.length();
    string maxx = "";
    int maxx_length = 0;
    for(int i = 0; i < length; i++)
    {
        string ex = "";
        int count = 0;
        for(int j = i; j < length; j++)
        {
            ex = s[j] + ex;
            count++;
            if(s.substr(i, j - i + 1) == ex && count > maxx_length)
            {
                maxx = ex;
                maxx_length = count;
            }
        }
    }
    return maxx;
}

//better (string expansion technique)
//time: O(n^2)
//s[ace: O(1)
string longestPalindrome1(string s) {
    int length = s.length();
    if(length == 1) return s;
    int max_len = 1;
    string maxx = "";

    for(int i = 0; i < length - 1; i++)
    {
        //l and r value is the only difference between odd and even case
        //even case
        int l = i;
        int r = i + 1;
        while(l >= 0 && r < length)
        {
            if(s[l] == s[r])
            {
                if(max_len < r - l + 1)
                {
                    max_len = r - l + 1;
                    maxx = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
            else
                break;
        }

        //odd case
        l = i - 1;
        r = i + 1;
        while(l >= 0 && r < length)
        {
            if(s[l] == s[r])
            {
                if(max_len < r - l + 1)
                {
                    max_len = r - l + 1;
                    maxx = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
            else
                break;
        }
        // cout << max_len << " " << maxx << endl;
    }
    return maxx;
}