class Solution
{
    private:
    int f(Node* root,int &moves) {
        if(!root) return 0;
        int l = f(root->left,moves);
        int r = f(root->right,moves);
        moves += abs(l) + abs(r);
        return l + r + root->key - 1;
    }
    public:
    int distributeCandy(Node* root)
    {
        //code here
        int moves = 0;
        f(root,moves);
        return moves;
    }
};