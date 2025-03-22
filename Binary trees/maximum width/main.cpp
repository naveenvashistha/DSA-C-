#include <bits/stdc++.h>

using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

//time: O(n)
//space: O(n)
int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    long maxx = 1;
    long start, end;
    while(!q.empty())
    {
        long size = q.size();
        for(int i = 0; i < size; i++)
        {
            pair<TreeNode*, unsigned long long> p = q.front();
            q.pop();
            if(i == 0) start = p.second;
            if(i == size - 1) end = p.second;
            if(p.first->left) q.push({p.first->left, 2 * p.second + 1});
            if(p.first->right) q.push({p.first->right, 2 * p.second + 2});
        }
        maxx = max(maxx, end - start + 1);
    }
    return maxx;
}