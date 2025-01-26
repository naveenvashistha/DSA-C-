#include <bits/stdc++.h>

using namespace std;

int countPrimes(int n);

int main()
{
    cout << countPrimes(20) << endl;
}

//orgasmic
int countPrimes(int n) {
    vector<int> v(n, 1);
    int count = 0;
    for(long i = 2; i < n; i++)
    {
        if(v[i] == 1)
        {
            long j = i;
            while(i * j < n)
            {
                v[i * j] = 0;
                j++;
            }
            count++;
        }
    }
    return count;
}