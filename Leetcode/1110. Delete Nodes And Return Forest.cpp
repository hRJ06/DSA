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
    vector<TreeNode*> ans;
    TreeNode* f(TreeNode* root, unordered_set<int> &s) {
        if(!root) return NULL;
        root->left = f(root->left,s);
        root->right = f(root->right,s);
        if(s.find(root->val) != s.end()) {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            delete(root);
            return NULL;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        if(f(root,s)) ans.push_back(root);
        return ans;
    }
};
