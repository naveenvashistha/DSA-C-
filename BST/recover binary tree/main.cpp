#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(n)
void inorder(TreeNode* node, vector<TreeNode*>& ino, int& a, int& b, int& count)
{
    if(node == NULL) return;
    inorder(node->left, ino, a, b, count);
    if(ino.size() != 0 && ino.back()->val > node->val){
        if(count == 1){
            a = ino.size() - 1;
            b = a + 1;
            count++;
        }
        else{
            b = ino.size();
        }
    }
    ino.push_back(node);
    inorder(node->right, ino, a, b, count);
}
void recoverTree(TreeNode* root) {
    vector<TreeNode*> ino;
    int a = -1, b = -1, count = 1;
    inorder(root, ino, a, b, count);
    swap(ino[a]->val, ino[b]->val);
}