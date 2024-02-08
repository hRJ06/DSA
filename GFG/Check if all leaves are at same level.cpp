class Solution{
  private:
    bool ans = true;
    void f(Node* root,int level,int &pre) {
        if(!root) return;
        if(!root->left and !root->right) {
            if(pre != -1 and level != pre) ans = false;
            else pre = level;
            return;
        }
        f(root->left,level + 1,pre);
        f(root->right,level + 1,pre);
    }
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        int level = -1;
        f(root,0,level);
        return ans;
    }
};