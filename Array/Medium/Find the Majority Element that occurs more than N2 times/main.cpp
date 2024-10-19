#include <bits/stdc++.h>

using namespace std;

int majority1(int arr[], int n);
int majority2(int arr[], int n);

int main()
{
    int arr[] = {2,2,2,1,1,2,2,0};
    // int n = majority1(arr, 6);
    int n = majority2(arr, 8);
    cout << n << endl; 
}

//better approach
//time: O(n) for best and average but O(n^2) for worst
//space: O(1)
int majority1(int arr[], int n)
{
    unordered_map<int, int> temp;
    for(int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
        if(temp[arr[i]] > n / 2)
            return arr[i];
    }    
    return -1;
}

//Moore’s Voting Algorithm
//time: O(n)
//space: O(1)
int majority2(int arr[], int n)
{
    int count = 1, element = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == element)
        {
            count++;
        }
        else
        {
            if(count != 0)
                count--;
            else
            {
                element = arr[i];
                count++;
            }
        }
    }
    return element;
}