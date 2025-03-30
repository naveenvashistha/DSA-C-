#include <bits/stdc++.h>

using namespace std;


//brute would be install a key after looking through entire tree each time
//time: O(n^2)
//space: O(1)

//better would be sort the preorder and create a inorder array and then create the tree from preorder and inorder array
//time: O(nlogn)
//space: O(n)

//my solution
//time: O(n)
//space: O(n)
TreeNode* bstFromPreorder(vector<int>& preorder) {
    stack<pair<TreeNode*, pair<int, int>>> st;
    TreeNode* root = new TreeNode(preorder[0]);
    st.push({root, {preorder[0], INT_MAX}});
    st.push({root, {INT_MIN, preorder[0]}});
    int i = 1;
    while(i < preorder.size())
    {
        pair<TreeNode*,pair<int, int>> p;
        while(true){
            p = st.top();
            st.pop();
            if(preorder[i] > p.second.first && preorder[i] < p.second.second) break;
        }
        TreeNode* new_node = new TreeNode(preorder[i]);
        if(preorder[i] < p.first->val) p.first->left = new_node;
        else p.first->right = new_node;
        st.push({new_node, {preorder[i], p.second.second}});
        st.push({new_node, {p.second.first, preorder[i]}});
        i++;
    }
    return root;
}

//orgasmic
//time: O(n)
//space: O(n)
TreeNode* build(vector<int>& preorder, int& i, int upper_bound)
{
    if(i >= preorder.size() || preorder[i] > upper_bound) return NULL;
    TreeNode* node = new TreeNode(preorder[i++]);
    node->left = build(preorder, i, node->val);
    node->right = build(preorder, i, upper_bound);
    return node;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}