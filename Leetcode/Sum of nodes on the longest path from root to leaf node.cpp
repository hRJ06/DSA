class Solution
{
private:
    int ans = 0, level = 0;
    void f(Node* root,int total,int cur) {
        if(!root) return;
        total += root->data;
        if(!root->left and !root->left) {
            if(cur > level) {
                ans = total;
                level = cur;
            }
            else if(cur == level)
                ans = max(ans,total);
        }
        if(root->left) f(root->left,total,cur + 1);
        if(root->right) f(root->right,total,cur + 1);
    }
public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        f(root,0,0);
        return ans;
    }
};