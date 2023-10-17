class Solution {
private:
    int findRoot(int n, vector<int>& leftChild, vector<int>& rightChild) {
        set<int> s;
        s.insert(leftChild.begin(), leftChild.end());
        s.insert(rightChild.begin(), rightChild.end());
        for(int i = 0; i<n; i++) {
            if(s.find(i) == s.end()) return i;
        }
        return -1;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if(root == -1) return false;
        unordered_set<int> check;
        queue<int> q;
        q.push(root);
        check.insert(root); 
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            vector<int> children({leftChild[node], rightChild[node]});
            for(auto &j : children) {  
                if(j != -1) {
                    if(check.find(j) != check.end()) return false;
                    q.push(j);
                    check.insert(j);  
                }
            }
        }
        return check.size() == n;
    }
};
