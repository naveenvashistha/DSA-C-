#include <bits/stdc++.h>

using namespace std;



//optimal
//time: O(n)
//space: O(1)
void findnode(TreeNode* node, int& ans, int& cnt, int k)
{
    if(node == NULL || cnt >= k) return;
    findnode(node->left, ans, cnt, k);
    cnt++;
    if(cnt == k){
        ans = node->val;
        return;
    }
    findnode(node->right, ans, cnt, k);
}
int kthSmallest(TreeNode* root, int k) {
    int cnt = 0, ans = -1;
    findnode(root, ans, cnt, k);
    return ans;
}