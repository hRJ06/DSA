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
    TreeNode* f(TreeNode* root,int sv,int dv) {
        if(!root) return NULL;
        if(root->val == sv or root->val == dv) return root;
        auto left = f(root->left,sv,dv);
        auto right = f(root->right,sv,dv);
        if(left and right) return root;
        return left ? left : right;
    }
    bool dir(TreeNode* root,int v,string &s) {
        if(!root) return false;
        if(root->val == v) return true;
        s.push_back('L');
        if(dir(root->left,v,s)) return true;
        s.pop_back();
        s.push_back('R');
        if(dir(root->right,v,s)) return true;
        s.pop_back();
        return false;
    }   
public:
    string getDirections(TreeNode* root, int sv, int dv) {
        TreeNode* lca = f(root,sv,dv);
        string s1 = "", s2 = "";
        dir(lca,sv,s1);
        dir(lca,dv,s2);
        for(auto &i : s1) i = 'U';
        return s1 + s2;
    }
};
