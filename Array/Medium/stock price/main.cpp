#include <bits/stdc++.h>

using namespace std;

int stock1(int arr[], int n);
int stock2(int arr[], int n);

int main()
{
    int arr[] = {7,1,5,3,6,4};
    // int n = stock1(arr, 6);
    int n = stock2(arr, 6);
    cout << n << endl; 
}

//brute force
//time: O(n^2)
//space: O(1)
int stock1(int arr[], int n)
{
    int maxi = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] > arr[i])
                maxi = max(maxi, arr[j] - arr[i]);
        }
    }
    return maxi;
}

//orgasmic approach
//time: O(n)
//space: O(1)
int stock2(int arr[], int n)
{
    int mini = arr[0], maxi = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < mini)
            mini = arr[i];
        else
            maxi = max(arr[i] - mini, maxi);
    }
    return maxi;
}