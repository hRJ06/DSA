class Solution
{   private:
    pair<bool,int> helper(Node* root) {
        if(!root) return {true,0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        bool check;
        if(!root->left and !root->right)
            check = true;
        else
            check = root->data == left.second + right.second and left.first and right.first;
        int total = left.second + right.second + root->data;
        return {check,total};
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
        return helper(root).first;
    }
};