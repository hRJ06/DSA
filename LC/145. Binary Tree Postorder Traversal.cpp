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
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        function<void(TreeNode*)> f = [&](TreeNode* root) {
            if(!root) return;
            f(root->left);
            f(root->right);
            ans.push_back(root->val);
        };
        f(root);
        return ans;
    }
};