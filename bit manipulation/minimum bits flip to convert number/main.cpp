#include <bits/stdc++.h>

using namespace std;

int minBitFlips(int start, int goal);


int main()
{
    cout << minBitFlips(7, 10) << endl;
}

//orgasmic
//time: O(log(max(start, goal)))
//space: O(1)
int minBitFlips(int start, int goal) {
    int i = 0;
    int cnt = 0;
    while(start != goal)
    {
        if((start & (1 << i)) != (goal & (1 << i)))
        {
            start = start ^ (1 << i);
            cnt++;
        }
        i++;
    }
    return cnt;
}