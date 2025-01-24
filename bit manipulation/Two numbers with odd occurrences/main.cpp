#include <bits/stdc++.h>

using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N);

int main()
{
    long long Arr[] = {1,1,2,2,3,4};
    vector<long long> v = twoOddNum(Arr, 6);
    cout << v[0] << " " << v[1] << endl;
}


//better soln would be to use hashmap

//orgasmic
//time: O(n)
//space: O(1)
vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
    long long num = 0, b1 = 0, b2 = 0;
    for(int i = 0; i < N; i++)
    {
        num ^= Arr[i];
    }
    num = (num & (num - 1)) ^ num;
    for(int i = 0; i < N; i++)
    {
        if((Arr[i] & num) == 0) b1 ^= Arr[i];
        else b2 ^= Arr[i];
    }
    if(b1 > b2) return {b1, b2};
    return {b2, b1};
}