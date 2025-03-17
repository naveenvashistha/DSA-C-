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

//my method
//time: O(n)
//space: O(n)
int height(TreeNode* node, int h)
{
    if(node == NULL) return h;
    int h1 = height(node->left, h + 1);
    int h2 = height(node->right, h + 1);
    return max(h1, h2);
}

//strivers
//time: O(n)
//space: O(n)
int height1(TreeNode* node)
{
    if(node == NULL) return 0;
    int h1 = height1(node->left);
    int h2 = height1(node->right);
    return 1 + max(h1, h2);
}
int maxDepth(TreeNode* root) {
    int ans = height(root, 0);
    return ans;
}