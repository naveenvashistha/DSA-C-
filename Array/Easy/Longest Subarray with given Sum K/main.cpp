#include <bits/stdc++.h>

using namespace std;

int lenOfLongSubarr1(int A[],  int N, int K);
int lenOfLongSubarr2(int A[],  int N, int K);

int main()
{
    // int num[]  = {8, 15, 17, 0, 11};
    int num[]  = {2,2,0,0,0,3};
    // int n = lenOfLongSubarr1(num, 5, 17);
    int n = lenOfLongSubarr2(num, 6, 3);
    cout << n << endl;
}

//time: O(n)
//space: O(1)
//my approach and also optimal solution for 0s and positives
int lenOfLongSubarr1(int A[],  int N, int K)
{
    int sum = 0, j = 0;
    int max = 0;
    for(int i = 0; i < N; i++)
    {
        sum += A[i];
        while(sum > K && i != j)
        {
            sum -= A[j];
            j++;
        }
        if(sum == K && i - j + 1 > max)
        {
            max = i - j + 1;
        }
    }
    return max;
}

//optimal solution if array contains both positives and negatives
//time: O(n) for best and avg case but O(n^2) for worst
//space: O(n)
int lenOfLongSubarr2(int A[],  int N, int K)
{
    unordered_map<int, int> search;
    int sum = 0;
    int max_len = 0;
    for(int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum == K)
            max_len = max(i + 1, max_len);
        else if(search.find(sum - K) != search.end())
            max_len = max(i - search[sum - K], max_len);    
        if(search.find(sum) == search.end())
            search[sum] = i;
    }
    return max_len;
}