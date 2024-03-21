class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	if(!root) return {};
    	vector<vector<int>> store;
    	bool f = true;
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()) {
    	    int n = q.size();
    	    vector<int> v(n);
    	    for(int i = 0; i<n; i++) {
    	        auto node = q.front();
    	        q.pop();
    	        if(f) v[i] = node->data;
    	        else v[n - i - 1] = node->data;
    	        if(node->left) q.push(node->left);
    	        if(node->right) q.push(node->right);
    	    }
    	    f = !f;
    	    store.push_back(v);
    	}
    	vector<int> ans;
    	for(auto &i : store) 
    	    for(auto &j : i) 
    	       ans.push_back(j);
    	return ans;
    }
};
