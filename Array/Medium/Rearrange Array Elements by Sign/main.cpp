#include <bits/stdc++.h>

using namespace std;

void rearrange1(vector<int>& arr, int n);
void rearrange2(vector<int>& arr, int n);
void rearrange3(vector<int>& arr, int n);

int main()
{
    vector<int> arr = {1,2,-3,-1,-2,-3};
    int n = arr.size();
    // rearrange1(arr, n);
    // rearrange2(arr, n);
    rearrange3(arr, n);
    cout << endl; 
}

//my approach
//time: O(2n)
//space: O(n)
void rearrange1(vector<int>& arr, int n)
{
    queue<int> pos, neg;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
            pos.push(arr[i]);
        else
            neg.push(arr[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            arr[i] = pos.front();
            pos.pop();
        }    
        else
        {
            arr[i] = neg.front();
            neg.pop();
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

//optimized
//time: O(n)
//space: O(n)
void rearrange2(vector<int>& arr, int n)
{
    int pos = 0, neg = 1;
    int i = 0;
    vector<int> temp(n, 0);
    while(pos < n || neg < n)
    {
        if(arr[i] > 0)
        {
            temp[pos] = arr[i];
            pos += 2;
        }
        else
        {
            temp[neg] = arr[i];
            neg += 2;
        }
        i++;    
    }
    for(int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
}

//if equal no of positives and negatives are not present (my approach and orgasmic too)
//time:
//space: 
void rearrange3(vector<int>& arr, int n)
{
    queue<int> pos, neg;
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
            pos.push(arr[i]);
        else
            neg.push(arr[i]);
    }
    while(!pos.empty() && !neg.empty())
    {
        if(k % 2 == 0)
        {
            arr[k] = pos.front();
            pos.pop();
        }
        else
        {
            arr[k] = neg.front();
            neg.pop();
        }
        k++;
    }
    for(int i = k; i < n; i++)
    {
        if(pos.empty() == 1)
        {
            arr[i] = neg.front();
            neg.pop();
        }
        else
        {
            arr[i] = pos.front();
            pos.pop();
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}