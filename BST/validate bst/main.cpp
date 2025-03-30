#include <bits/stdc++.h>

using namespace std;



//brute
//time: O(n)
//space: O(n)
void inorder(TreeNode* node, vector<int> &ino){
    if(node == NULL) return;
    inorder(node->left, ino);
    ino.push_back(node->val);
    inorder(node->right, ino);
}
bool isValidBST(TreeNode* root) {
    vector<int> ino;
    inorder(root, ino);
    for(int i = 0; i < ino.size() - 1; i++)
    {
        if(ino[i] >= ino[i + 1]) return false;
    }
    return true;
}

//optimal
//time: O(n)
//space: O(n)
bool checkBST(TreeNode* node, long minn, long maxx)
{
    if(node == NULL) return true;
    if(node->val > minn && node->val < maxx){
        bool b1 = checkBST(node->left, minn, node->val);
        bool b2 = checkBST(node->right, node->val, maxx);
        return b1 && b2;
    }
    return false;
}
bool isValidBST(TreeNode* root) {
    return checkBST(root, LONG_MIN, LONG_MAX);
}