#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(nlogn)
//space: O(n)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int> pq;
    for(auto list: lists)
    {
        ListNode* head = list;
        while(head != NULL)
        {
            pq.push(head->val);
            head = head->next;
        }
    }
    ListNode* head = NULL;
    while(!pq.empty())
    {
        ListNode* new_node = new ListNode(pq.top());
        new_node->next = head;
        head = new_node;
        pq.pop();
    }
    return head;
}

int main()
{
}

