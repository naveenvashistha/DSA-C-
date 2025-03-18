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

//my solution
//time: O(n)
//space: O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    int level = 0;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        vector<int> temp;
        if(level % 2 == 0)
        {
            while(!s1.empty())
            {
                TreeNode* node = s1.top();
                s1.pop();
                temp.push_back(node->val);
                if(node->left) s2.push(node->left);
                if(node->right) s2.push(node->right);
            }
        }
        else
        {
            int size = s2.size();
            while(!s2.empty())
            {
                TreeNode* node = s2.top();
                s2.pop();
                temp.push_back(node->val);
                if(node->right) s1.push(node->right);
                if(node->left) s1.push(node->left);
            }
        }
        level++;
        ans.push_back(temp);
    }
    return ans;
}

//orgasmic
//time: O(n)
//space: O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    bool flag = 0;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(flag == 0)
            {
                temp[i] = node->val;
            }
            else
            {
                temp[size - 1 - i] = node->val;
            }
        }
        flag = !flag;
        ans.push_back(temp);
    }
    return ans;
}