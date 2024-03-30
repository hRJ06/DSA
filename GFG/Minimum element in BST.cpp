class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        int ans = root->data;
        while(root->left) {
            root = root->left;
            ans = root->data;
        }
        return ans;
    }
};
