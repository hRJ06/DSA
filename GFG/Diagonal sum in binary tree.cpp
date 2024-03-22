class Solution {
  public:
    vector<int> diagonalSum(Node* root) {
        if(!root) return {};
        queue<Node*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()) {
            int total = 0, n = q.size();
            for(int i = 0; i<n; i++) {
                auto top = q.front();
                q.pop();
                while(top) {
                    total += top->data;
                    if(top->left)
                        q.push(top->left);
                    top=top->right;
                }
            }
            v.push_back(total);
        }
        return v;
    }
};