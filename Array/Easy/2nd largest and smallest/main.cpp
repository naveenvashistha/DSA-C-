#include <bits/stdc++.h>

using namespace std;

void secondLargestSmallest1(vector<double> &arr, int size);
void secondLargestSmallest2(vector<double> &arr, int size);

int main()
{
    int size, n;
    vector<double> num;
    cout << "size: ";
    cin >> size;
    if (size <= 1) 
    {
        cout << "-1" << endl;
        return 0;
    }
    while(size--)
    {
        cin >> n;
        num.push_back(n);
    }
    //secondLargestSmallest1(num, num.size());
    secondLargestSmallest2(num, num.size());
}

//time: O(n)
//space: O(1)
//without sorting - approach 1
void secondLargestSmallest1(vector<double> &arr, int size)
{
    int max, min, second_min, second_max;
    max = min = arr[0];
    for(int i = 1; i < size; i++)
    {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    second_min = max;
    second_max = min;
    for(int i = 0; i < size; i++)
    {
        if (max > arr[i] && arr[i] > second_max) second_max = arr[i];
        if (min < arr[i] && arr[i] < second_min) second_min = arr[i];
    }
    if (max == min)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << "second largest: " << second_max << endl;
        cout << "second smallest: " << second_min << endl;
    }
}

//time: O(n)
//space: O(1)
//without sorting - approach 2 (better)
void secondLargestSmallest2(vector<double> &arr, int size)
{
    int max, min, sec_min, sec_max;
    max = sec_max = INT_MIN;
    min = sec_min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            sec_max = max;
            max = arr[i];
        }
        else if (sec_max < arr[i] && arr[i] != max) 
        {
            sec_max = arr[i];
        }
        if (min > arr[i])
        {
            sec_min = min;
            min = arr[i];
        }
        else if (sec_min > arr[i] && arr[i] != min)
        {
            sec_min = arr[i];
        }
    }
    if (min == max) cout << "-1" << endl;
    else cout << "second largest: " << sec_max << " second smallest: " << sec_min << endl;
}