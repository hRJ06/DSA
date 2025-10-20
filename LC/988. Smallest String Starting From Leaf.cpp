class Solution {
private:
    void helper(TreeNode* root,string &cur) {
        if(!root) return;
        cur += root->val + 'a';
        if(!root->left and !root->right) {
            string s = cur;
            reverse(s.begin(),s.end());
            ans = min(ans,s);
        }
        helper(root->left,cur);
        helper(root->right,cur);
        cur.pop_back();
    }
public:
    string ans = "~";
    string smallestFromLeaf(TreeNode* root) {
        string cur = "";
        helper(root,cur);
        return ans;
    }
};