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
    TreeNode* create(int s,int e,vector<int> &in) {
        if(s > e) return NULL;
        int m = s + (e - s) / 2;
        TreeNode* root = new TreeNode(in[m]);
        root->left = create(s,m - 1,in);
        root->right = create(m + 1,e,in);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        function<void(TreeNode*)> f = [&](TreeNode* r) -> void {
            if(!r) return;
            f(r->left);
            in.push_back(r->val);
            f(r->right);
        };
        f(root);
        int n = in.size();
        return create(0,n - 1,in);
    }
};