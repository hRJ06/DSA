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
    vector<vector<int>> ans;
    void f(TreeNode* root,int k,vector<int> v) {
        if(!root) return;
        v.push_back(root->val);
        if(!root->left and !root->right and !(k - root->val)) ans.push_back(v);
        f(root->left,k - root->val,v);
        f(root->right,k - root->val,v);
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        f(root,k,{});
        return ans;
    }
};