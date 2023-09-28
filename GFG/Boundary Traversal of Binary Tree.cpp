class Solution {
private:
    void left(Node* root,vector<int> &ans) {
        if(!root or (!root->left and !root->right)) return;
        ans.push_back(root->data);
        if(root->left)
            left(root->left,ans);
        else
            left(root->right,ans);
    }
    void leaf(Node* root,vector<int> &ans) {
        if(!root) return;
        if(!root->left and !root->right) ans.push_back(root->data);
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
    void right(Node* root,vector<int> &ans) {
        if(!root or (!root->left and !root->right)) return;
        if(root->right)
            right(root->right,ans);
        else
            right(root->left,ans);
        ans.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root->left and !root->right) {
            ans.push_back(root->data);
            return ans;
        }
        ans.push_back(root->data);
        left(root->left,ans);
        leaf(root,ans);
        right(root->right,ans);
        return ans;
    }
};