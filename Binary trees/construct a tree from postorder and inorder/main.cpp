#include <bits/stdc++.h>

using namespace std;


//time: O((n)
//space: O(h)
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int current, int start, int end, unordered_map<int, int>& mp)
{
    TreeNode* node = new TreeNode(postorder[current]);
    int ind = mp[postorder[current]];
    int temp = current;
    if(ind != end){
        current = current - 1;
        node->right = buildTree(inorder, postorder, current, ind + 1, end, mp);
    }
    if(ind != start){
        current = temp - (end - ind) - 1;
        node->left = buildTree(inorder, postorder, current, start, ind - 1, mp);
    }
    return node;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> mp;
    for(int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode* root = buildTree(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1, mp);
    return root;
}