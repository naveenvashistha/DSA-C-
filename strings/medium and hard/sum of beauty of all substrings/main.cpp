#include <bits/stdc++.h>

using namespace std;

int beautySum(string s);

int main()
{
    string s = "aba";
    int ss = beautySum(s);
    cout << ss << endl;
}

//orgasmic
//time: O(n^3)
//space: O(1)
int beautySum(string s) {
    int length = s.length();
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        int freq[26] = {0};
        int highest = INT_MIN;
        for(int j = i; j < length; j++)
        {
            int lowest = INT_MAX;
            freq[s[j] - 'a']++;
            if(freq[s[j] - 'a'] > highest) highest = freq[s[j] - 'a'];
            for(int k = 0; k < 26; k++)
            {
                if(freq[k] != 0 && freq[k] < lowest)
                    lowest = freq[k];
            }
            count += (highest - lowest);
        }
    }
    return count;
}