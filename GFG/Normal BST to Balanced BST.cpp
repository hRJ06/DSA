class Solution{
    private:
    void in(Node* root,vector<int> &inorder) {
        if(!root) return;
        in(root->left,inorder);
        inorder.push_back(root->data);
        in(root->right,inorder);
    }
    Node* build(vector<int> &inorder,int s,int e) {
        if(s > e) return NULL;
        int m = s + (e - s) / 2;
        Node* root = new Node(inorder[m]);
        root->left = build(inorder,s,m - 1);
        root->right = build(inorder,m + 1,e);
        return root;
    }
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<int> inorder;
    	in(root,inorder);
    	return build(inorder,0,inorder.size() - 1);
    }
};