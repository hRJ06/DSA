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
    vector<TreeNode*> leaf;
    int ans = 0;
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto top = q.front();
            bool isLeaf = true;
            q.pop();
            if(top->left) {
                parent[top->left] = top;
                q.push(top->left);
                isLeaf = false;
            }
            if(top->right) {
                parent[top->right] = top;
                q.push(top->right);
                isLeaf = false;
            }
            if(isLeaf) leaf.push_back(top);
        }
    }
    void dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*> &parent, unordered_map<TreeNode*, bool> &vis, int dist, int k) {
        if(dist > k or !node or vis[node]) return;
        if(dist and !node->left and !node->right) ans++;
        vis[node] = true;
        dfs(node->left, parent, vis, dist + 1, k);
        dfs(node->right, parent, vis, dist + 1, k);
        dfs(parent[node], parent, vis, dist + 1, k);
        vis[node] = false;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, TreeNode*> parent;
        mark_parent(root, parent);
        for(auto &i : leaf) {
            unordered_map<TreeNode*, bool> vis;
            dfs(i, parent, vis, 0, distance);
        }
        return ans / 2;
    }
};
