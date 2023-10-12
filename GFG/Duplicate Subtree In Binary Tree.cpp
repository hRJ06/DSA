class Solution {
  private:
    string f(Node* root,unordered_map<string,int> &mp) {
        if(!root) return "n";
        if(!root->left and !root->right) return to_string(root->data);
        string ans = "";
        ans += f(root->left,mp);
        ans += f(root->right,mp);
        ans += root->data;
        mp[ans]++;
        return ans;
    }
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
         // code here
        unordered_map<string,int> mp;
        f(root->left,mp);
        f(root->right,mp);
        for(auto &i : mp)
            if(i.second > 1) return 1;
        return 0;
    }
};