class Solution
{
    private:
    set<Node*> st;
    void f(Node* root,vector<Node*> v,int k) {
        if(!root) return;
        v.push_back(root);
        if(!root->left and !root->right) {
            int s = v.size();
            if(s - k - 1 >= 0) st.insert(v[s - k - 1]);
        }
        f(root->left,v,k);
        f(root->right,v,k);
    }
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here.
    	f(root,{},k);
    	return st.size();
    }
};