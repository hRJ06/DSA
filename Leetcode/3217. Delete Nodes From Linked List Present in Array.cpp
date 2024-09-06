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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* d = new ListNode(-1);
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode *t = d, *temp = head;
        while(temp) {
            if(s.find(temp->val) == s.end()) {
                t->next = temp;
                t = t->next;
            }
            temp = temp->next;
        }
        t->next = NULL;
        return d->next;
    }
};