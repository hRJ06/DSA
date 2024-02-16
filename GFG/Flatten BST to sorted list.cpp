class Solution
{
private:
    Node* f(Node* root) {
        if(!root) return NULL;
        Node* left = f(root->left);
        Node* right = f(root->right);
        if(left) {
            Node* t = left;
            while(t->right) {
                t = t->right;
            }
            t->right = root;
            root->left = NULL;
        }
        root->right = right;
        return left ? left : root;
    }
public:
    Node *flattenBST(Node *root)
    {
        // code here
        return f(root);
    }
};