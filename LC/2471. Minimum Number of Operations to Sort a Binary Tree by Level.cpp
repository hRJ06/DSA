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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> v;
            while(n--) {
                auto top = q.front();
                q.pop();
                v.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            int size = v.size();
            unordered_map<int, int> mp;
            for(int i = 0; i<size; i++) {
                mp[v[i]] = i;
            }
            vector<int> store = v;
            sort(begin(store), end(store));
            for(int i = 0; i<size; i++) {
                if(v[i] != store[i]) {
                    ans++;
                    int index = mp[store[i]];
                    v[index] = v[i];
                    mp[v[i]] = index;
                }
            }
        }
        return ans;
    }
};