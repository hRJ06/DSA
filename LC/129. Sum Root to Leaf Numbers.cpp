class Solution {
private:
    int helper(TreeNode* root,int cur) {
        if(!root) return 0;
        cur = (cur * 10) + root->val;
        if(!root->left and !root->right) return cur;
        return helper(root->left,cur) + helper(root->right,cur);
    }
public:
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};