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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> par;
        for(auto &i : descriptions) {
            TreeNode *parent = NULL, *children = NULL;
            if(mp.count(i[0])) {
                parent = mp[i[0]];
            }
            else {
              parent = new TreeNode(i[0]);
              mp[i[0]] = parent;
            }
            if(mp.count(i[1])) {
                children = mp[i[1]];
            }
            else {
              children = new TreeNode(i[1]);
              mp[i[1]] = children;
            }
            if(i[2]) parent->left = children;
            else parent->right = children;
            par[i[1]] = i[0];
        }
        for(auto &i : mp) {
            if(!par.count(i.first)) return i.second;
        }
        return NULL;
    }
};
