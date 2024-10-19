#include <bits/stdc++.h>

using namespace std;

vector<int> union_array1(int arr1[], int arr2[], int n, int m);
vector<int> union_array2(int arr1[], int arr2[], int n, int m);
vector<int> union_array3(int arr1[], int arr2[], int n, int m);

int main()
{
    int arr1[] = {1,2,3,4};
    int arr2[] = {3,3,3,4,7,8};
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);
    //vector<int> num = union_array1(arr1, arr2, n, m);
    //vector<int> num = union_array2(arr1, arr2, n, m);
    vector<int> num = union_array3(arr1, arr2, n, m);
    for(auto i: num)
    {
        cout << i << " ";
    }
    cout << endl;
}

//approach using pointers
//time: 
//space: O(n + m)
vector<int> union_array1(int arr1[], int arr2[], int n, int m) {
    vector<int> num;
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(arr1[i] <= arr2[j])
        {
            if(num.size() == 0 || num.back() != arr1[i])
                num.push_back(arr1[i]);
            i++;
        }
        else
        {
            if(num.size() == 0 || num.back() != arr2[j])
                num.push_back(arr2[j]);
            j++;
        }
    }
    while(i < n)
    {
        if(num.back() != arr1[i])
            num.push_back(arr1[i]);
        i++;
    }
    while(j < m)
    {
        if(num.back() != arr2[j])
            num.push_back(arr2[j]);
        j++;
    }
    return num;
}

//approach 2 using map
//time: O((m+n)log(m+n))
//space: O(m+n)
vector<int> union_array2(int arr1[], int arr2[], int n, int m)
{
    map<int, int> temp;
    vector<int> union_res;
    for(int i = 0; i < n; i++)
        temp[arr1[i]]++;
    for(int i = 0; i < m; i++)
        temp[arr2[i]]++;
    for(auto i: temp)
        union_res.push_back(i.first);
    return union_res; 
}

//approach 3 using set
//time and space complexity same as map
vector<int> union_array3(int arr1[], int arr2[], int n, int m)
{
    set<int> temp;
    vector<int> union_res;
    for(int i = 0; i < n; i++)
        temp.insert(arr1[i]);
    for(int i = 0; i < m; i++)
        temp.insert(arr2[i]);
    for(auto i: temp)
        union_res.push_back(i);
    return union_res; 
}