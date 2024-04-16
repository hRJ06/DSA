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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            depth--;
            while(n--) {
                auto node = q.front();
                q.pop();
                TreeNode *l = node->left, *r = node->right;
                if(depth == 1) {
                    node->left = new TreeNode(val);
                    node->left->left = l;
                    node->right = new TreeNode(val);
                    node->right->right = r;
                }
                else {
                    if(l) q.push(l);
                    if(r) q.push(r);
                }
            }
        }
        return root;
    }
};