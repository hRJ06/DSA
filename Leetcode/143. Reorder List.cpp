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
private:
    ListNode* mid(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode *head) {
        ListNode *prev = NULL, *cur = head, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* m = mid(head);
        ListNode* t = reverse(m->next);
        m->next = NULL;
        ListNode* store = head;
        while(t) {
            ListNode* next = store->next;
            store->next = t;
            ListNode* t_next = t->next;
            t->next = next;
            t = t_next;
            store = store->next->next;
        }
    }
};