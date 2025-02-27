#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n*m)
//space: O(1)
string minWindow(string& s1, string& s2) {
    // Write your Code here
    int k = 0;
    int min_len = INT_MAX;
    int min_start = 0;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == s2[k])
        {
            k++;
            if(k == s2.size())
            {
                k--;
                int end = i + 1;
                while(k >= 0)
                {
                    if(s2[k] == s1[i]) k--;
                    i--;
                }
                i++;
                k++;
                if(min_len > end - i)
                {
                    min_len = end - i;
                    min_start = i;
                }
            }
        }
    }
    if(min_len == INT_MAX) return "";
    return s1.substr(min_start, min_len);
}


int main()
{
}

