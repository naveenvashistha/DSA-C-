#include <bits/stdc++.h>

using namespace std;


//time: O((n)
//space: O(h)
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int current, int start, int end)
{
    TreeNode* node = new TreeNode(preorder[current]);
    int ind;
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == preorder[current])
        {
            ind = i;
            break;
        }
    }
    int temp = current;
    if(ind != start){
        current = current + 1;
        node->left = buildTree(preorder, inorder, current, start, ind - 1);
    }
    if(ind != end){
        current = temp + (ind - start) + 1;
        node->right = buildTree(preorder, inorder, current, ind + 1, end);
    }
    return node;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    return root;
}