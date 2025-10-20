/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans = 0;
    int f(TreeNode* r) {
        if(!r) return 0;
        int lA = f(r->left), rA = f(r->right);
        ans += abs(lA) + abs(rA);
        return r->val + lA + rA - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        f(root);
        return ans;
    }
};