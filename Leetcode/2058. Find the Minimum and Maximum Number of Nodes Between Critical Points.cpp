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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int p = 0, count = 0, index = 0, f = INT_MAX, prev = head->val;
        int mini = INT_MAX;
        ListNode* t = head;
        while(t and t->next) {
            if((t->val > prev and t->val > t->next->val) or (t->val < prev and t->val < t->next->val)) {
                if(count)
                    mini = min(mini,index - count);
                f = min(f, index);
                count = index;
            }
            index++;
            prev = t->val;
            t = t->next;
        }
        if(mini != INT_MAX) return {mini, count - f};
        return {-1, -1};
    }
};