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
    unordered_map<int,int> node_level;
    unordered_map<int,int> height;
    int levelMax[100001], levelSecondMax[100001];

    int dfs(TreeNode* root, int level) {
        if(!root) return 0;
        node_level[root->val] = level;
        int left = dfs(root->left, level + 1);
        int right = dfs(root->right, level + 1);
        int h = 1 + max(left, right);

        if(h > levelMax[level]) {
            levelSecondMax[level] = levelMax[level];
            levelMax[level] = h;
        }
        else if(h > levelSecondMax[level]) {
            levelSecondMax[level] = h;
        }

        return height[root->val] = h;
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        vector<int> ans;
        for(auto &i : queries) {
            int level = node_level[i];
            int rem;
            if(height[i] != levelMax[level]) rem = levelMax[level];
            else rem = levelSecondMax[level];
            ans.push_back(level + rem - 1);
        }
        return ans;
    }
};