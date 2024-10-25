#include <bits/stdc++.h>

using namespace std;

void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n);
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n);
void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n);
void merge4(vector<int>& nums1, int m, vector<int>& nums2, int n);
void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2);

int main()
{
    // vector<int> a = {2,5,6,0,0,0};
    // vector<int> b = {1,2,3};
    vector<int> a = {2,5,6};
    vector<int> b = {1,2,3};
    merge4(a,3,b,3);
    for(auto i: a)
    {
        cout << i << " ";
    }
    for(auto i: b)
    {
        cout << i << " ";
    }
}

//my approach (leetcode problem)
//time: O(n) + O(nlogn)
//space: O(1)
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    for(int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[i - m];
    }
    sort(nums1.begin(), nums1.end());
}

//my approach (strivers problem)
//time: O(n*nlogn)
//space: O(1)
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    for(int i = 0; i < m; i++)
    {
        if(nums1[i] > nums2[0])
        {
            swap(nums1[i], nums2[0]);
            sort(nums2.begin(), nums2.end());
        }
    }
}

//orgasmic (strivers problem)
//time: O(n) + O(2*nlogn)
//space: O(1)
void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m - 1;
    int j = 0;
    while(i >= 0 && j < n)
    {
        if(nums1[i] > nums2[j])
        {
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

//gap method and orgasmic in nature
//time: O((n+m)*log(n+m))
//space: O(1)
void merge4(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int gap = ceil((m + n)/2.0);
    int left, right;
    while(gap > 0)
    {
        left = 0, right = gap;
        while(right < m + n)
        {
            //arr1 and arr2
            if(left < m && right >= m)
                swapIfGreater(nums1, nums2, left, right - m);
            //arr2 and arr2
            else if(left >= m)
                swapIfGreater(nums2, nums2, left - m, right - m);
            //arr1 and arr1
            else
                swapIfGreater(nums1, nums1, left, right);
            left++;
            right++;
        }

        if(gap == 1) break;
        gap = ceil(gap / 2.0);
    }
}

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2)
{
    if(arr1[ind1] > arr2[ind2])
        swap(arr1[ind1], arr2[ind2]);
}