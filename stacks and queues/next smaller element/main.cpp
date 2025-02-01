
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& nums);
vector<int> nextSmalllerElement1(vector<int> &A);

int main()
{
    vector<int> n = {4,2,1};
    vector<int> ans = nextSmallerElement(n);
    for(auto i: ans)
        cout << i << endl;
}

//orgasmic
//time: O(n)
//space: O(n)
vector<int> nextSmallerElement(vector<int>& nums) {
    stack<int> st;
    vector<int> ans(nums.size(), -1);

    for(int i = nums.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() >= nums[i])
            st.pop();
        if(!st.empty()) ans[i] = st.top();
        st.push(nums[i]);
    }
    return ans;
}

//different variant
vector<int> nextSmalllerElement1(vector<int> &A)
{
    stack<int> st;
    vector<int> ans(A.size(), -1);
    for(int i = 0; i < A.size(); i++)
    {
        while(!st.empty() && st.top() >= A[i])
            st.pop();
        if(!st.empty()) ans[i] = st.top();
        st.push(A[i]);
    }
    return ans;
}


