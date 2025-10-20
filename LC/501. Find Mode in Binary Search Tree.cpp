class Solution {
private:
    int cS = 0, mS = 0, cN = 0;
    vector<int> ans;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        if(cN == root->val) cS++;
        else {
            cS = 1;
            cN = root->val;
        }
        if(cS > mS) {
            ans = {};
            mS = cS;
        }
        if(cS == mS) ans.push_back(root->val);
        dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};