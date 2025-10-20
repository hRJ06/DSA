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
    int length(ListNode* head) {
        if(!head) return 0;
        return 1 + length(head->next);
    } 
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int sr = 0, sc = 0, er = m - 1, ec = n - 1;
        int count = length(head); 
        ListNode* t = head;
        while(count) {
            for(int i = sc; i<=ec and count; i++, t = t->next, count--) {
                ans[sr][i] = t->val;
            }
            sr++;
            for(int i = sr; i<=er and count; i++, t = t->next, count--) {
                ans[i][ec] = t->val;
            }
            ec--;
            for(int i = ec; i>=sc and count; i--, t = t->next, count--) {
                ans[er][i] = t->val;
            }
            er--;
            for(int i = er; i>=sr and count; i--, t = t->next, count--) {
                ans[i][sc] = t->val;
            }
            sc++;
        }
        return ans;
    }
};