class Solution {
private:
    Node* f(Node* node,unordered_map<Node*,Node*> &mp) {
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        vector<Node*> newNeighbor;
        for(auto &i : node->neighbors) {
            if(mp.count(i)) newNeighbor.push_back(mp[i]);
            else newNeighbor.push_back(f(i,mp));
        }
        newNode->neighbors = newNeighbor;
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        return f(node,mp);
    }
};