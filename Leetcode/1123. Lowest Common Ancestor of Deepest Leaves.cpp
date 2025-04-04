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
        TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root or root == p or root == q) return root;
            TreeNode* left = LCA(root->left, p, q);
            TreeNode* right = LCA(root->right, p, q);
            if(!left) return right;
            else if(!right) return left;
            else return root;
        }
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            unordered_map<int, vector<TreeNode*>> mp;
            int level = 0;
            queue<pair<TreeNode*, int>> q;
            q.push({root, 0});
            while(!q.empty()) {
                auto top = q.front();
                q.pop();
                TreeNode* node = top.first;
                int cur = top.second;
                level = max(level, cur);
                mp[cur].push_back(node);
                if(node->left) {
                    q.push({node->left, cur + 1});
                }
                if(node->right) {
                    q.push({node->right, cur + 1});
                }
            }
            return LCA(root, mp[level][0], mp[level][mp[level].size() - 1]);
        }
    };