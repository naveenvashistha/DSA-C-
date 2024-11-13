#include <bits/stdc++.h>

using namespace std;

int k1(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k);
int k2(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k);
int k3(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k);

int main()
{
    vector<int> n1 = {3} , n2 = {-2,-1};
    int n = k2(n1, n2, 1, 2, 2);
    cout << n << endl;
}

//brute force
//time: O(n)
//space: O(n)
int k1(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k)
{
    int i = 0, j = 0;
    vector<int> temp;
    while(i < n1 && j < n2)
    {
        if(nums1[i] <= nums2[j])
        {
            temp.push_back(nums1[i]);
            i++;
        }
        else
        {
            temp.push_back(nums2[j]);
            j++;
        }
    }
    for(int k = i; k < n1; k++)
    {
        temp.push_back(nums1[k]);
    }
    for(int k = j; k < n2; k++)
    {
        temp.push_back(nums2[k]);
    }
    return temp[k - 1];
}

//better
//time: O(n)
//space: O(1)
int k2(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k)
{
    int i = 0, j = 0, cnt = 0, first = 0, second = 0;
    while(i < n1 && j < n2)
    {
        cnt++;
        if(nums1[i] <= nums2[j])
        {
            if(cnt == k) return nums1[i];
            i++;
        }
        else
        {
            if(cnt == k) return nums2[j];
            j++;
        }
    }

    while(i < n1)
    {
        cnt++;
        if(cnt == k) return nums1[i];
        i++;
    }

    while(j < n2)
    {
        cnt++;
        if(cnt == k) return nums2[j];
        j++;
    }
    return 0;
}

//orgasmic
//time: O(logn)
//space: O(1)
int k3(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k)
{
    if(n1 > n2) return k3(nums2, nums1, n2, n1, k);
    int low = 0, high = min(k, n1), mid1, mid2;
    if(k > n2) low = k - n2;
    int l1, l2, r1, r2;
    while(low <= high)
    {
        mid1 = (low + high) / 2;
        mid2 = k - mid1;
        l1 = INT_MIN;
        l2 = INT_MIN;
        if(mid1 != 0)
            l1 = nums1[mid1 - 1];
        if(mid2 != 0)
            l2 = nums2[mid2 - 1];
        r1 = INT_MAX;
        r2 = INT_MAX;
        if(mid1 != n1)
            r1 = nums1[mid1];
        if(mid2 != n2)
            r2 = nums2[mid2];
        if(l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if(l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return -1;
}