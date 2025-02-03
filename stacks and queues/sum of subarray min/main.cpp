
#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& arr);
int sumSubarrayMins1(vector<int>& arr); 

int main()
{
    vector<int> n = {4,2,1};
    cout << sumSubarrayMins1(n) << endl;
}

//brute
//time: O(n^2)
//space: O(1)
int sumSubarrayMins(vector<int>& arr) {
    int minsub = INT_MAX;
    int m = 1e9 + 7;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        minsub = INT_MAX;
        for(int j = i; j < arr.size(); j++)
        {
            minsub = min(minsub, arr[j]);
            sum = (sum + minsub) % m;
        }
    }
    return sum;
}

//orgasmic
//time: O(n)
//space: O(n)
int sumSubarrayMins1(vector<int>& arr) {
    stack<int> st;
    stack<int> stt;
    int m = 1e9 + 7;
    int sum = 0;
    vector<int> nse(arr.size());
    vector<int> pse(arr.size());

    for(int i = arr.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if(!st.empty())
            nse[i] = st.top();
        else nse[i] = arr.size();
        st.push(i);
    }

    for(int i = 0; i < arr.size(); i++)
    {
        while(!stt.empty() && arr[stt.top()] > arr[i])
            stt.pop();
        if(!stt.empty())
            pse[i] = stt.top();
        else
            pse[i] = -1;
        stt.push(i);
    }

    for(int i = 0; i < arr.size(); i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;

        sum = (sum + (left * right * (long long)1 * arr[i])) % m ;
    }
    return sum;
}