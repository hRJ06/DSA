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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int n = q.size(), total = 0;
            for(int i = 0; i<n; i++) {
                auto top = q.front();
                q.pop();
                total += top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            mp[level++] = total;
        }
        /* TRANSFORM */
        root->val = 0; 
        queue<pair<TreeNode*, int>> q2;
        q2.push({root, 0});
        while(!q2.empty()) {
            auto top = q2.front();
            q2.pop();
            auto node = top.first;
            int level = top.second;
            int total = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
            if(node->left) {
                node->left->val = mp[level + 1] - total;
                q2.push({node->left, level + 1});
            }
            if(node->right) {
                node->right->val = mp[level + 1] - total;
                q2.push({node->right, level + 1});
            }
        }  
        return root;
    }
};