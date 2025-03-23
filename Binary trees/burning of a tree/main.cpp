#include <bits/stdc++.h>

using namespace std;


//time: O(n)
//space: O(n)
Node* findTarget(Node* node, int target)
{
    if(node == NULL) return NULL;
    if(node->data == target) return node;
    Node* a = findTarget(node->left, target);
    Node* b = findTarget(node->right, target);
    if(!a && !b) return NULL;
    else if(a == NULL) return b;
    else return a;
}
int minTime(Node* root, int target) {
    // code here
    queue<Node*> q;
    unordered_map<Node*, Node*> mp;
    q.push(root);
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        if(n->left){
            mp[n->left] = n;
            q.push(n->left);
        }
        if(n->right){
            mp[n->right] = n;
            q.push(n->right);
        }
    }
    Node* tgt = findTarget(root, target);
    q.push(tgt);
    int sec = 0;
    unordered_set<Node*> m;
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            Node* node = q.front();
            q.pop();
            if(node->left && m.find(node->left) == m.end()) q.push(node->left);
            if(node->right && m.find(node->right) == m.end()) q.push(node->right);
            if(mp.find(node) != mp.end() && m.find(mp[node]) == m.end()) q.push(mp[node]);
            m.insert(node);
        }
        sec++;
    }
    return sec - 1;
}