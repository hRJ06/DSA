class Solution
{
    private:
    Node* LCA(Node* root,int x,int y) {
        if(!root) return NULL;
        if(root->data > x and root->data > y) {
            return LCA(root->left,x,y);
        }
        else if(root->data < x and root->data < y) {
            return LCA(root->right,x,y);
        }
        return root;
    }
    public:
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        Node* lca = LCA(root,x,y);
        if(!lca) return -1;
        stack<Node*> s;
        Node* cur = root;
        while(cur != lca) {
            s.push(cur);
            if(cur->data > lca->data) cur = cur->left;
            else cur = cur->right;
        }
        // Push LCA
        s.push(lca);
        while(!s.empty() and k > 1) {
            s.pop();
            k--;
        }
        if(s.empty()) return -1;
        return s.top()->data;
    }
};