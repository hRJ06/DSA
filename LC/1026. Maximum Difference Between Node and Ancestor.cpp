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
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        int a = INT_MIN, b = INT_MAX;
        function<void(TreeNode*,int,int)> f = [&](TreeNode* root,int a,int b) {
            if(!root) {
                ans = max(ans,abs(a - b));
                return;
            }
            a = max(a,root->val);
            b = min(b,root->val);
            f(root->left,a,b);
            f(root->right,a,b);
        };
        f(root,a,b);
        return ans;
    }
};