#include <bits/stdc++.h>

using namespace std;

//time: O(nlogn)
//space: O(n)
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
    // code here
    priority_queue<pair<int, pair<int, int>>> pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;
    set<pair<int, int>> s;
    pq.push({A[N - 1] + B[N - 1], {N - 1, N - 1}});
    s.insert({N - 1, N - 1});
    while(ans.size() != K)
    {
        ans.push_back(pq.top().first);
        int l = pq.top().second.first;
        int r = pq.top().second.second;
        pq.pop();
        if(l > 0 && s.find({l - 1, r}) == s.end())
        {
            pq.push({A[l - 1] + B[r], {l - 1, r}});
            s.insert({l - 1, r});
        }
        if(r > 0 && s.find({l, r - 1}) == s.end())
        {
            pq.push({A[l] + B[r - 1], {l, r - 1}});
            s.insert({l, r - 1});
        }
    }
    return ans;
}
int main()
{
}

