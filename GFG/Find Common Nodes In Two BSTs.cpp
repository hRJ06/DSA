
class Solution
{
    private:
    void f(Node* root,map<int,int> &mp) {
        if(!root) return;
        mp[root->data]++;
        f(root->left,mp);
        f(root->right,mp);
    }
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        //Your code here
        map<int,int> mp;
        f(root1,mp);
        f(root2,mp);
        vector<int> ans;
        for(auto &i : mp) if(i.second > 1) ans.push_back(i.first);
        return ans;
    }
};