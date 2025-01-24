#include <bits/stdc++.h>

using namespace std;

vector<int> AllPrimeFactors(int n);
vector<int> AllPrimeFactors1(int n);
bool isPrime(int n);

int main()
{
    vector<int> v = AllPrimeFactors1(100);
    for(auto i: v)
    {
        cout << i << endl;
    }
}

bool isPrime(int n)
{
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

//better
//time: O(rootN * rootN)
//space: not defined
vector<int>AllPrimeFactors(int N) {
    // Code here
    vector<int> v;
    for(int i = 1; i <= sqrt(N); i++)
    {
        if(N % i == 0)
        {
            if(isPrime(i)) v.push_back(i);
            if(N / i != i)
            {
                if(isPrime(N / i)) v.push_back(N / i);
            }
        }
    }
    return v;
}

//simple prime factorisation of number
//orgasmic
//time: O(sqrt(n) * logn)
//space: not defined
vector<int> AllPrimeFactors1(int n){
    vector<int> v;
    for(int i = 2; i <= sqrt(n); i++)
    {
        
        if(n % i == 0)
        {
            v.push_back(i);
            while(n % i == 0) n = n / i;    
        }
        if(n == 1) return v;
    }
    if(n != 1) v.push_back(n);
    return v;
}