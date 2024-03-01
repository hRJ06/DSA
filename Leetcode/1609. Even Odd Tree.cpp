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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto node = q.front();
                q.pop();
                if(l & 1) {
                    if(node->val % 2 or (n > 0 and node->val <= q.front()->val)) return false;
                }
                else {
                    if(!(node->val % 2) or (n > 0 and node->val >= q.front()->val)) return false;
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            l++;
        }
        return true;
    }
};