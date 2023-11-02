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
    pair<int,int> f(TreeNode* root) {
        if(!root) return {0,0};
        auto l = f(root->left);
        auto r = f(root->right);
        int s = l.second + r.second + root->val;
        int n = 1 + l.first + r.first;
        ans += (s / n) == root->val;
        return {n,s};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};