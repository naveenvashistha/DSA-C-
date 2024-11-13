#include <bits/stdc++.h>

using namespace std;

double median1(vector<int>& nums1, vector<int>& nums2);
double median2(vector<int>& nums1, vector<int>& nums2);
double median3(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int> n1 = {3} , n2 = {-2,-1};
    double n = median2(n1, n2);
    cout << n << endl;
}

//brute force
//time: O(n)
//space: O(n)
double median1(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
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
    if((n1 + n2) % 2 == 0) return (temp[(n1 + n2) / 2] + temp[(n1 + n2) / 2 - 1]) / 2.0;
    return temp[(n1 + n2) / 2];
}

//better
//time: O(n)
//space: O(1)
double median2(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    int size = n1 + n2;
    int i = 0, j = 0, cnt = 0, first = 0, second = 0;
    while(i < n1 && j < n2)
    {
        cnt++;
        if(nums1[i] <= nums2[j])
        {
            if(cnt == size / 2) first = nums1[i];
            if(cnt == size / 2 + 1) second = nums1[i];
            i++;
        }
        else
        {
            if(cnt == size / 2) first = nums2[j];
            if(cnt == size / 2 + 1) second = nums2[j];
            j++;
        }
    }

    while(i < n1)
    {
        cnt++;
        if(cnt == size / 2) first = nums1[i];
        if(cnt == size / 2 + 1) second = nums1[i];
        i++;
    }

    while(j < n2)
    {
        cnt++;
        if(cnt == size / 2) first = nums2[j];
        if(cnt == size / 2 + 1) second = nums2[j];
        j++;
    }

    if(size % 2 == 0) return (first + second) / 2.0;
    return (double)second;
}

//orgasmic
//time: O(logn)
//space: O(1)
double median3(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    if(n1 > n2) return median3(nums2, nums1);
    int low = 0, high = nums1.size(), mid1, mid2;
    int partition = (n1 + n2 + 1) / 2;
    int l1, l2, r1, r2;
    while(low <= high)
    {
        mid1 = (low + high) / 2;
        mid2 = partition - mid1;
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
            if((n1+n2) % 2 == 0) 
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            return max(l1, l2);
        }
        else if(l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return -1;
}