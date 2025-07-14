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
    ListNode* reverse(ListNode* head) {
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
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        int ans = 0, index = 0;
        ListNode* t = head;
        while(t) {
            if(t->val) ans += pow(2, index);
            t = t->next;
            index++;
        }
        return ans;
    }
};
