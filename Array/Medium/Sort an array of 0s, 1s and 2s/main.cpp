#include <bits/stdc++.h>

using namespace std;

void sort012_1(int arr[], int n);
void sort012_2(int arr[], int n);

int main()
{
    int arr[] = {2,0,2,1,1,0};
    // sort012_1(arr, 6);
    sort012_2(arr, 6);
    for(auto i: arr)
        cout << i << " ";
    cout << endl; 
}

void sort012_1(int nums[], int n)
{
    int ones = 0, twos = 0, zeros = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 1)
            ones++;
        else if(nums[i] == 2)
            twos++;
    }
    zeros = n - (ones + twos);
    for(int i = 0; i < n; i++)
    {
        if(i < zeros)
            nums[i] = 0;
        else if(i < zeros + ones)
            nums[i] = 1;
        else
            nums[i] = 2;
    }
}

//dutch national flag problem
//0 to low - 1 are all 0
// low to mid - 1 are all 1
// mid to high contains unsorted array
// high + 1 to n - 1 are all 2
//time: O(n)
//space: O(1)
void sort012_2(int nums[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    
}