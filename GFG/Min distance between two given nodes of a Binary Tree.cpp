class Solution{
private:
     int f(Node* root, int a){
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                Node* node = q.front().first;
                int level = q.front().second;
                q.pop();
                if(node->data == a) return level;
                if(node->left) q.push({node->left, level + 1});
                if(node->right) q.push({node->right, level + 1});
            }
        }
        return 0;
    }
    Node* lca(Node* root, int a, int b) {
        if(!root) return NULL;
        if(root->data == a or root->data == b) return root;
        Node* left = lca(root->left, a, b);
        Node* right = lca(root->right, a, b);
        if(left and right) return root;
        else if(left and !right) return left;
        else return right;
    }
    
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* parent = lca(root, a, b); 
        int s1 = f(parent, a); 
        int s2 = f(parent, b); 
        return s1 + s2;
    }
};