
class Solution
{
    private:
        int ans = 0;
        void f(Node* root) {
            if(!root) return;
            if(!root->left and !root->right) ans += root->data;
            f(root->left);
            f(root->right);
        }
    public:
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root){
             /*Your code here */
            f(root);
            return ans;
        }
};