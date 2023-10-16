//User function Template for C++
class DSU {
    public:
    vector<int> rank, parent, size;
    DSU(int n) {
        rank.resize(n + 1,0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    } 
};
class Solution
{
private:
    bool isValid(int r,int c,int n) {
        return r >= 0 and r < n and c >= 0 and c < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n = grid.size();
        DSU ds(n * n);
        int dir[] = {-1,0,1,0,-1};
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]) {
                    for(int k = 0; k<4; k++) {
                        int r = i + dir[k];
                        int c = j + dir[k + 1];
                        if(isValid(r,c,n) and grid[r][c]) {
                            int node = i * n + j;
                            int adjNode = r * n + c;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(!grid[i][j]) {
                    set<int> components;
                    for(int k = 0; k<4; k++) {
                        int r = i + dir[k];
                        int c = j + dir[k + 1];
                        if(isValid(r,c,n) and grid[r][c]) components.insert(ds.findUPar(r * n + c));
                    }
                    int size = 1;
                    for(auto &it : components) size += ds.size[it];
                    ans = max(ans, size);
                }
            }
        }
        ans = max(ans,ds.size[ds.findUPar(0)]);
        return ans;
    }
};