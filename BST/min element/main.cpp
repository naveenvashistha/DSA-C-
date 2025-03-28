#include <bits/stdc++.h>

using namespace std;




//time: O(n)
//space: O(1)
int minValue(Node* root) {
    // Code here
    while(root->left != NULL) root = root->left;
    return root->data;
}