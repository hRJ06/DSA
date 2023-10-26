typedef long long ll;
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            ll total = 0;
            while(n--) {
                auto top = q.front();
                q.pop();
                total += top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            if(pq.size() < k) pq.push(total);
            else {
                if(total > pq.top()) {
                    pq.pop();
                    pq.push(total);
                }
            }
        }
        return pq.size() < k ? -1 : pq.top();
    }
};