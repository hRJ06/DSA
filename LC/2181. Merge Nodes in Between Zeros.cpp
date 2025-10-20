/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* t = head->next;
        ListNode *d = new ListNode(-1), *i = d;
        int total = 0;
        while(t) {
            if(!t->val) {
                i->next = new ListNode(total);
                i = i->next;
                total = 0;
            }
            else
                total += t->val;
            t=t->next;
        }
        return d->next;
    }
};