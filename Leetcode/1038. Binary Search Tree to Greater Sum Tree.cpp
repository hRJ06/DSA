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
    int total = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return root;
        bstToGst(root->right);
        total += root->val;
        root->val = total;
        bstToGst(root->left);
        return root;
    }
};