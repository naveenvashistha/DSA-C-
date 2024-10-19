#include <bits/stdc++.h>

using namespace std;

long long sumOfDivisors(int N);

int main()
{
    int N;
    cin >> N;
    cout << sumOfDivisors(N) << endl; 
}


//time - O(N)
//space - O(1)
long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long sum = 0;
        for (int i = 1; i <= N; i++)
        {
            sum += (N / i) * i;
        }
        return sum;
    }