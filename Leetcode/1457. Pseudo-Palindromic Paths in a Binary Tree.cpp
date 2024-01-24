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
    void f(TreeNode* root,vector<int> &v) {
        if(!root) return;
        v[root->val]++;
        if(!root->left and !root->right) {
            int odd = 0;
            for(auto &i : v) {
                if(i & 1) odd++;
            }
            if(odd <= 1) ans++;
        }
        f(root->left,v);
        f(root->right,v);
        v[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        f(root,v);
        return ans;
    }
};