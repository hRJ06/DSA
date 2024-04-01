class Solution
{   
    private:
        int ans = INT_MAX, prev = -1;
        void f(Node* root) {
            if(!root) return;
            f(root->left);
            if(prev != -1) 
                ans = min(ans,root->data - prev);
            prev = root->data;
            f(root->right);
        }
    public:
        int absolute_diff(Node *root)
        {
            //Your code here
            f(root);
            return ans;
        }
};