class Solution{
    private:
    int ans = 1;
    private:
    int f(Node *root) {
        if(!root) return 0;
        if(!root->left and !root->right) return root->data;
        int left = f(root->left);
        int right = f(root->right);
        if(root->data != (left + right)) ans = 0;
        return root->data;
    }
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
        f(root);
        return ans;
    }
};