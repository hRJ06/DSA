class Solution {
private:
    Node* helper(Node* root, int target) {
        if(!root) return NULL;
        if(root->data == target) return root;
        Node* left = helper(root->left, target);
        if(left) return left;
        Node* right = helper(root->right, target);
        return right;
    }
public:
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        unordered_map<Node*, Node*> mp;
        unordered_map<Node*, bool> vis;
        function<void()> f = [&]() -> void {
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        };
        Node* find = helper(root, target);
        queue<Node*> q;
        q.push(find);
        f();
        while(!q.empty() and k > 0) {
            int n = q.size();
            while (n--) {
                auto node = q.front();
                q.pop();
                vis[node] = true;
                if(node->left and !vis[node->left])
                    q.push(node->left);
                if(node->right and !vis[node->right])
                    q.push(node->right);
                if(mp.find(node) != mp.end() and !vis[mp[node]])
                    q.push(mp[node]);
            }
            k--;
        }
        vector<int> ans;
        while (!q.empty()) {
            auto node = q.front();
            ans.push_back(node->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};