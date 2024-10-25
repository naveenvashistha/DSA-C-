#include <bits/stdc++.h>

using namespace std;

vector<int> findMissingRepeatingNumbers1(vector<int> a);
vector<int> findMissingRepeatingNumbers2(vector<int> a);
vector<int> findMissingRepeatingNumbers3(vector<int> a);
vector<int> findMissingRepeatingNumbers4(vector<int> a);

int main()
{
    vector<int> a = {2,5,6};
    vector<int> ans = findMissingRepeatingNumbers1(a);
    for(auto i: ans)
    {
        cout << i << " ";
    }
}

//my approach and also better approach
//time: O(n)
//space: O(n)
vector<int> findMissingRepeatingNumbers1(vector<int> a)
{
    unordered_map<int, int> m;
    int n = a.size();
    int sum = 0;
    int repeat, missing;
    for(int i = 0; i < n; i++)
    {
        m[a[i]]++;
        if(m[a[i]] > 1)
            repeat = a[i];
        sum += a[i];
    }
    missing = (n * (n + 1)) / 2 - (sum - repeat);
    return {repeat, missing};
}

//orgasmic approach
//time: O(n)
//space: O(1)
vector<int> findMissingRepeatingNumbers2(vector<int> a)
{
    long long repeat, missing;
    long long n = a.size();
    long long Sn = 0, Sx = 0, S2n = 0, S2x = 0;
    for(int i = 0; i < n; i++)
    {
        Sx += a[i];
        S2x += (long long)a[i] * (long long)a[i];
    }
    Sn = (n * (n + 1)) / 2;
    S2n = (n * (n + 1) * (2 * n + 1)) / 6;
    missing = ((S2n - S2x) / (Sn - Sx) + Sn - Sx) / 2;
    repeat = missing - Sn + Sx;
    return {(int)repeat, (int)missing};
}

vector<int> findMissingRepeatingNumbers3(vector<int> a)
{
    long long repeat, missing;
    long long n = a.size();
    long long Sn = 0, Sx = 0, S2n = 0, S2x = 0;
    for(int i = 0; i < n; i++)
    {
        Sx += a[i];
        S2x += (long long)a[i] * (long long)a[i];
    }
    Sn = (n * (n + 1)) / 2;
    S2n = (n * (n + 1) * (2 * n + 1)) / 6;
    missing = ((S2n - S2x) / (Sn - Sx) + Sn - Sx) / 2;
    repeat = missing - Sn + Sx;
    return {(int)repeat, (int)missing};
}

vector<int> findMissingRepeatingNumbers4(vector<int> a)
{
    int n = a.size();
    int xr = 0;
    for(int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }
    //getting differentiating bit
    int bitn = 0;
    while(1)
    {
        if((xr & (1 << bitn)) != 0)
            break;
        else
            bitn++;
    }
    //dividing into ones and zeros group
    int ones = 0, zeroes = 0;
    for(int i = 0; i < n; i++)
    {
        if((a[i] & (1 << bitn)) != 0)
            ones = ones ^ a[i];
        else
            zeroes = zeroes ^ a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if((i & (1 << bitn)) != 0)
            ones = ones ^ i;
        else
            zeroes = zeroes ^ i;
    }
    //determining whether ones is repeat or missing number
    for(int i = 0; i < n; i++)
    {
        if(a[i] == ones)
            return {ones, zeroes};
        else if(a[i] == zeroes)
            return {zeroes, ones};
    }
}