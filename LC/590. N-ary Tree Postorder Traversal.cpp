/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> ans;
public:
    vector<int> postorder(Node* root) {
        function<void(Node*)> f = [&](Node* root) {
            if(!root) return;
            for(auto &i : root->children)
                f(i);   
            ans.push_back(root->val);
        };
        f(root);
        return ans;
    }
};