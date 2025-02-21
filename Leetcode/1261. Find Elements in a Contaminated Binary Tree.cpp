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
 class FindElements {
    public:
        unordered_map<int, bool> mp;
        FindElements(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            root->val = 0;
            while(!q.empty()) {
                auto top = q.front();
                mp[top->val] = true;
                q.pop();
                if(top->left) {
                    top->left->val = 2 * top->val + 1;
                    q.push(top->left);
                }
                if(top->right) {
                    top->right->val = 2 * top->val + 2;
                    q.push(top->right);
                }
            }
        }
        
        bool find(int target) {
            return mp.count(target);
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */