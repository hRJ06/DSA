class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      if(!root) return {};
      queue<Node*> q;
      q.push(root);
      vector<int> ans;
      while(!q.empty()) {
          auto top = q.front();
          q.pop();
          ans.push_back(top->data);
          if(top->left) q.push(top->left);
          if(top->right) q.push(top->right);
      }
      return ans;
    }
};