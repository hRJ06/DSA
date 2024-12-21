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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            vector<TreeNode*> v;
            int n = q.size();
            while(n--) {
                auto node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                    v.push_back(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                    v.push_back(node->right);
                }
            }
            if(++level % 2) {
                int n = v.size();
                for(int i = 0; i<n/2; i++)
                    swap(v[i]->val,v[n - i - 1]->val);
            }
        }
        return root;
    }
};