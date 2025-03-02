#include <bits/stdc++.h>

using namespace std;

//my solution
//time: O(nlogn)
//space: O(1)
void heapifyUp(vector<int> &arr, int i)
{
    int p = (i - 1) / 2;
    while(i > 0 && arr[i] > arr[p])
    {
        swap(arr[i], arr[p]);
        i = p;
        p = (p - 1) / 2;
    }
}
void convertMinToMaxHeap(vector<int> &arr, int N){
    for(int i = N - 1; i >= 0; i--)
    {
        while(true)
        {
            int temp = arr[i];
            heapifyUp(arr, i);
            if(temp == arr[i]) break;
        }
    }
}

void heapifyDown(vector<int>& arr, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int n = arr.size();
    int biggest = i;
    if(l < n && arr[l] > arr[biggest])
        biggest = l;
    if(r < n && arr[r] > arr[biggest])
        biggest = r;
    if(biggest != i)
    {
        swap(arr[i], arr[biggest]);
        heapifyDown(arr, biggest);
    }
}

//online solution with same time and space complexity
void convertMinToMaxHeap(vector<int> &arr, int N){
    for(int i = N - 1; i >= 0; i--)
    {
        heapifyDown(arr, i);
    }
}

int main()
{
}

