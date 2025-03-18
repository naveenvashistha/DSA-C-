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

//optimal
//time: O(n)
//space: O(n)
int pathSum(TreeNode* node, int &max_path_sum)
{
    if(node == NULL) return 0;
    int h1 = pathSum(node->left, max_path_sum);
    int h2 = pathSum(node->right, max_path_sum);
    max_path_sum = max(max_path_sum, h1 + h2 + node->data);
    max_path_sum = max(max_path_sum, node->data);
    max_path_sum = max(max_path_sum, node->data + max(h1, h2));
    return max(node->data, node->data + max(h1, h2));
}
int maxPathSum(TreeNode* root) {
    int max_path_sum = INT_MIN;
    int a = pathSum(root, max_path_sum);
    return max(a, max_path_sum);
}