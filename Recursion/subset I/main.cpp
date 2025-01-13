#include <bits/stdc++.h>

using namespace std;

vector<int> subsetSums(vector<int>& arr);
void findSum(vector<int> &v, vector<int> arr, int sum, int ind);

int main()
{
    vector<int> arr = {2,3,6,7};
    vector<int> out = subsetSums(arr);
    for(auto i: out)
    {
        cout << i << endl;
    }
}

void findSum(vector<int> &v, vector<int> arr, int sum, int ind)
{
    if(ind == arr.size())
    {
        v.push_back(sum);
        return;
    }
    sum += arr[ind];
    findSum(v, arr, sum, ind + 1);
    
    sum -= arr[ind];
    findSum(v, arr, sum, ind + 1);
}

//orgasmic
//time: O(2^n)
//space: O(2^n)
vector<int> subsetSums(vector<int>& arr) {
    // code here
    vector<int> v;
    findSum(v, arr, 0, 0);
    return v;
}