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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* cur = head;
        for(;cur;cur = cur->next,len++);
        if(n == len) {
            ListNode* ans = head->next;
            delete head;
            return ans;
        }
        n = len - n - 1;
        cur = head;
        while(n--)
            cur = cur->next;
        ListNode* node = cur->next;
        cur->next = cur->next->next;
        delete node;
        return head;
    }
};