#include <bits/stdc++.h>

using namespace std;

int numberOfInversions1(vector<int>&a, int n);
int numberOfInversions2(vector<int>&a, int n);
void divide(vector<int>&a, int low, int high, int &cnt);
void sort_arr(vector<int>& a, int low, int high, int &cnt);

int main()
{
    vector<int> v = {4,3,2,1};
    int temp = numberOfInversions1(v, v.size());
    cout << temp << endl;
}

//brute force
//time: O(n^2)
//space: O(1)
int numberOfInversions1(vector<int>&a, int n)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
                cnt++;
        }
    }
    return cnt;
}

//orgasmic
//time: O(nlogn)
//space: O(n)
int numberOfInversions2(vector<int>&a, int n)
{
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
            cnt = cnt + (mid - i + 1);
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