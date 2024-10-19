#include <bits/stdc++.h>

using namespace std;

int missing1(vector<int>& nums, int n);
int missing2(vector<int>& nums, int n);
int missing3(vector<int>& nums, int n);
int missing4(vector<int>& nums, int n);

//Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N.
//Find the number(between 1 to N), that is not present in the given array.

int main()
{
    vector<int> num {1,2,3,4};
    // int n = missing1(num, 5);
    // int n = missing2(num, 5);
    // int n = missing3(num, 5);
    int n = missing4(num, 5);
    cout << n << endl;
}

//my approach
//time: O(nlogn)
//sapce: O(1)
int missing1(vector<int>& nums, int n) {
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 1; i++)
    {
        if(nums[i] != i + 1)
            return i + 1;
    }
    return n;
}

//hashing approach
//time: O(n)
//space: O(n)
int missing2(vector<int>& nums, int n) {
    int temp[n + 1] = {0};
    for(int i = 0; i < n - 1; i++)
    {
        temp[nums[i]]++;
    }
    for(int i = 1; i < n + 1; i++)
    {
        if(temp[i] == 0)
            return i;
    }
    return -1;
}

//optimal approach 1 using sum technique
//time: O(n)
//space: O(1)
int missing3(vector<int>& nums, int n) {
    int sum1 = 0;
    int sum2 = (n * (n + 1))/2;
    for(int i = 0; i < n - 1; i++)
    {
        sum1 += nums[i];
    }
    return sum2 - sum1;
}

//optimal approach 2 using xor technique
//time: O(n)
//space: O(1)
int missing4(vector<int>& nums, int n) {
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < n - 1; i++)
    {
        xor2 ^= nums[i];
        xor1 ^= i + 1;
    }
    xor1 ^= n;
    return xor2 ^ xor1;
}