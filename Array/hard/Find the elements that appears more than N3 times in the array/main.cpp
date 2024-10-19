#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement1(vector<int> v);
vector<int> majorityElement2(vector<int> v);

int main()
{
    vector<int> v = {2,2,0,1,2,1};
    // vector<int> temp = majorityElement1(v);
    vector<int> temp = majorityElement2(v);
    for(auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
}

//my approach and also better approach
//main point to remember is that there can be a maximum of 2 majority elements.
//time: O(n)
//space: O(n)
vector<int> majorityElement1(vector<int> v)
{
    unordered_map<int, int> m;
    int n = floor(v.size() / 3) + 1;
    vector<int> temp;
    for(auto i : v)
    {
        m[i]++;
        if(m[i] == n)
            temp.push_back(i);
        if(temp.size() == 2)
            break;
    }
    return temp;
}

//orgasmic approach
//extended moore's voting algo
//time: O(2n)
//space: O(1)
vector<int> majorityElement2(vector<int> v)
{
    int el1, el2, cnt1, cnt2;
    el1 = el2 = INT_MIN;
    cnt1 = cnt2 = 0;
    int n = floor(v.size() / 3) + 1;
    for(int i = 0; i < v.size(); i++)
    {
        if(cnt1 == 0 && el2 != v[i])
        {
            cnt1++;
            el1 = v[i];
        }
        else if(cnt2 == 0 && el1 != v[i])
        {
            cnt2++;
            el2 = v[i];
        }
        else if(el1 == v[i])
            cnt1++;
        else if(el2 == v[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = cnt2 = 0;
    vector<int> temp;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == el1)
            cnt1++;
        else if(v[i] == el2)
            cnt2++;
    }
    if(cnt1 >= n)
        temp.push_back(el1);
    if(cnt2 >= n)
        temp.push_back(el2);
    return temp;
}
