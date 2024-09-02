#include <bits/stdc++.h>

using namespace std;

int evenlyDivides(int N);

int main()
{
    int N;
    cin >> N;
    cout << evenlyDivides(N) << endl; 
}

int evenlyDivides(int N){
        int n = N;
        int i = 0;
        int k;
        while (n != 0)
        {
            k = n % 10;
            if (n % 10 != 0 && N % (n % 10) == 0)
            {
                i++;
            }
            n = n / 10;
        }
        return i;
    }