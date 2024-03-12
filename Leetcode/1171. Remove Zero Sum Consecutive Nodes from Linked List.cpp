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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0), *ans = dummy;
        dummy->next = head;
        unordered_map<int,ListNode*> mp;
        int total = 0;
        while(ans) {
            total += ans->val;
            if(mp.count(total)) {
                ans = mp[total]->next;
                int store = total + ans->val;
                while(store != total) {
                    mp.erase(store);
                    ans = ans->next;
                    store += ans->val;
                }
                mp[total]->next = ans->next;
            }
            else {
                mp[total] = ans;
            }
            ans = ans->next;
        }
        return dummy->next;
    }
};