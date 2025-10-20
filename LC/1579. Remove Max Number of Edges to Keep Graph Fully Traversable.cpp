class DSU {
    private:
        vector<int> parent;
        vector<int> rank;
        int components;
    public:
        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1);
            components = n;
            for(int i = 1; i<=n; i++) 
                parent[i] = i;
        }
        int find(int node) {
            if(parent[node] != node)
                return parent[node] = find(parent[node]);
            return node;
        }
        void Union(int x,int y) {
            int parent_x = find(x);
            int parent_y = find(y);
            if(parent_x != parent[y]) {
                if(rank[parent_x] < rank[parent_y])
                    parent[parent_x] = parent_y;
                else if(rank[parent_x] > rank[parent_y])
                    parent[parent_y] = parent_x;
                else {
                    parent[parent_x] = parent_y;
                    rank[parent_y]++;
                }
                components--;
            }
            else 
                return;
        }
        bool isSingle() {
            return components != 1 ? false : true;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] > b[0];
        });
        DSU Alice(n), Bob(n);
        int required = 0;
        for(auto &edge : edges) {
            int t = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(t == 3) {
                if(Alice.find(v) != Alice.find(u)) {
                    Alice.Union(u,v);
                    Bob.Union(u,v); 
                    required++;
                }
            }
            else if(t == 2) {
                if(Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    required++;
                }
            }
            else if(t == 1) {
                if(Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    required++;
                }
            }
        }
        if(Alice.isSingle() and Bob.isSingle()) 
            return edges.size() - required;
        return -1;
    }
};