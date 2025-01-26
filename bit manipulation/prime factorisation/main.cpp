#include <bits/stdc++.h>

using namespace std;

vector<int> findPrimeFactors(int N);
vector<int> findPrimeFactors1(int N);

int main()
{
    vector<int> n = findPrimeFactors(20);
    for(auto i: n)
    {
        cout << i << " ";
    }
    cout << endl;
}

//my solution
//time: no idea
//space: O(n)

vector<int> findPrimeFactors(int N) {

    // Write your code here
    vector<int> prime(N + 1, 1);
    vector<int> ans;
    for(int i = 2; i < N + 1; i++)
    {
        if(prime[i] == 1 && N % i == 0)
        {
            long j = i;
            while( j * i < N + 1)
            {
                prime[j * i] = 0;
                j++;
            }
            long k = i;
            while(k < N + 1)
            {
                if(N % k == 0) ans.push_back(i);
                k = k * i;
            }
        }
    }
    return ans;
}

//orgasmic
//time: O(n) + O(nloglogn) + O(logn)
//space: O(n)
vector<int> findPrimeFactors1(int N) {

    // Write your code here
    vector<int> ans;
    vector<int> v(N + 1);
    for(long i = 0; i < v.size(); i++) v[i] = i;
    
    for(long i = 2; i < N + 1; i++)
    {
        if(v[i] == i)
        {
            long j = i;
            while(j * i < N + 1)
            {
                if(v[j * i] == j * i)
                    v[i * j] = i;
                j++;
            }
        }
    }
    int k = N;
    while(k != 1)
    {
        ans.push_back(v[k]);
        k = k / v[k];
    }
    return ans;
}