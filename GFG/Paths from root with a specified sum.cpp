class Solution
{   
    private:
    void f(Node* root,vector<int> store,vector<vector<int>> &ans,int sum) {
        if(!root) return;
        sum -= root->key;
        store.push_back(root->key);
        if(!sum) ans.push_back(store);
        f(root->left,store,ans,sum);
        f(root->right,store,ans,sum);
    }
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<int> store;
        vector<vector<int>> ans;
        f(root,store,ans,sum);
        return ans;
    }
};