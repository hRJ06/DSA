class Solution{
    private:
    pair<bool,int> f(Node* root) {
        if(!root) return {true,0};
        auto left = f(root->left);
        auto right = f(root->right);
        bool balanced = abs(left.second - right.second) <= 1 and left.first and right.first;
        int height = 1 + max(left.second,right.second);
        return {balanced,height};
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return f(root).first;
        
    }
};