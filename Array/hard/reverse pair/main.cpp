#include <bits/stdc++.h>

using namespace std;

int reverse1(vector<int>&a);
int reverse2(vector<int>&a);
void divide(vector<int>&a, int low, int high, int &cnt);
void sort_arr(vector<int>& a, int low, int high, int &cnt);
void countPairs(vector<int> &a, int low, int high, int& cnt);

int main()
{
    vector<int> v = {3,2,1,4};
    int temp = reverse1(v);
    cout << temp << endl;
}

//brute force
//time: O(n^2)
//space: O(1)
int reverse1(vector<int>&a)
{
    int n = a.size();
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > 2 * a[j])
                cnt++;
        }
    }
    return cnt;
}

//orgasmic
//time: O(2*nlogn)
//space: O(n)
int reverse2(vector<int>&a)
{
    int n = a.size();
    int cnt = 0;
    divide(a, 0, n - 1, cnt);
    return cnt;
}

void divide(vector<int>&a, int low, int high, int &cnt)
{
    int mid = (low + high) / 2;
    if(low < high)
    {
        divide(a, low, mid, cnt);
        divide(a, mid + 1, high, cnt);
        sort_arr(a, low, high, cnt);
    }
}

void sort_arr(vector<int>& a, int low, int high, int &cnt)
{
    int mid = (low + high) / 2;
    int i = low;
    int j = mid + 1;
    vector<int> temp;
    countPairs(a, low, high, cnt);
    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while(j <= high)
    {
        temp.push_back(a[j]);
        j++;
    }
    for(int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void countPairs(vector<int> &a, int low, int high, int& cnt)
{
    int mid = (low + high) / 2;
    int i = low;
    int j = mid + 1;
    while(i <= mid && j <= high)
    {
        if(a[i] > 2 * a[j])
        {
            cnt = cnt + (mid - i + 1);
            j++;
        }
        else
        {
            i++;
        }
    }
}