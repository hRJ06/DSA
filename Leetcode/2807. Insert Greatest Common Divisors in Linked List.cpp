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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode* store = head; 
        while(store->next) {
            int gcd = __gcd(store->val, store->next->val);
            ListNode* next = store->next;
            store->next = new ListNode(gcd);
            store->next->next = next;
            store = store->next->next;
        }
        return head;
    }
};