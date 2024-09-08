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
    int len(ListNode* head) {
        if(!head) return 0;
        return 1 + len(head->next);
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = len(head);
        int each = n / k, extra = n % k;
        int index = 0;
        ListNode* t = head;
        vector<ListNode*> ans(k);
        while(t) {
            ans[index++] = t;
            int have = each + (extra > 0 ? 1 : 0) - 1;
            for(int i = 0; i<have; i++) t = t->next;
            extra--;
            ListNode* store = t->next;
            t->next = NULL;
            t = store;
        }
        return ans;
    }
};