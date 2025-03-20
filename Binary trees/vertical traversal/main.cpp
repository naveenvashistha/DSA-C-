#include <bits/stdc++.h>

using namespace std;


void traversal(TreeNode* node, map<int, vector<pair<int, int>>>& mp, int row, int col)
{
    if(node == NULL) return;
    mp[col].push_back({row, node->val});
    traversal(node->left, mp, row + 1, col - 1);
    traversal(node->right, mp, row + 1, col + 1);
}

//time: O(nlogn)
//space: O(n)
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<pair<int, int>>> mp;
    traversal(root, mp, 0, 0);
    vector<vector<int>> ans;
    for(auto col: mp)
    {
        vector<int> temp;
        sort(col.second.begin(), col.second.end());
        for(auto j: col.second)
        {
            temp.push_back(j.second);
        }
        ans.push_back(temp);
    }
    return ans;
}