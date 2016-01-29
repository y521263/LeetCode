//https://leetcode.com/problems/delete-node-in-a-linked-list/

#include<iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void deleteNode(ListNode* node) {
    ListNode* p = node->next;
    node->val = p->val;
    node->next = p->next;
    delete p;
}

int main()
{
    return 0;
}