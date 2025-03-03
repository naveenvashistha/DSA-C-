
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);
vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2);

// } Driver Code Ends
int main()
{
    vector<int> n = {4,2,1};
    vector<int> m = {1,4,3,2,5};   
    vector<int> ans = nextGreaterElement1(n, m);
    for(auto i: ans)
        cout << i << endl;
}

//orgasmic
//time: O(m + n)
//space: O(n)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    stack<int> st;
    vector<int> ans;

    for(int i = nums2.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= nums2[i])
            st.pop();
        if(st.empty()) mp[nums2[i]] = -1;
        else mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    for(int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}

//if circular array is allowed
vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    stack<int> st;
    vector<int> ans;

    for(int i = 2 * nums2.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= nums2[i % nums2.size()])
            st.pop();
        if(i < nums2.size()){
            if(st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
        }
        st.push(nums2[i % nums2.size()]);
    }
    for(int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}


