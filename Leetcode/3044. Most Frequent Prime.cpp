class Solution {
private:
    map<int,int> mp;
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}, {1,1}, {1,-1}, {-1,-1}, {-1,1}};
    bool isP(int n) {
        for(int i = 2; i<n; i++) {
            if(!(n % i)) return false;
        }
        return true;
    }
    bool f(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &mat,int m,int n) {
        if(i < 0 or j < 0 or i >= m or j >= n or vis[i][j]) return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &mat,int m,int n,int now,int k) {
        now = now * 10 + mat[i][j];
        vis[i][j] = 1;
        mp[now]++;
        if(f(i + dir[k][0],j + dir[k][1],vis,mat,m,n))
            dfs(i + dir[k][0],j + dir[k][1],vis,mat,m,n,now,k);
        vis[i][j] = 0;
    }
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++) 
            for(int j = 0; j<n; j++)
                for(int k = 0; k<8; k++)
                    dfs(i,j,vis,mat,m,n,0,k);
        int freq = 0, ans = -1;
        for(auto &i : mp) {
            if(i.first > 10 and isP(i.first) and i.second >= freq) {
                ans = i.first;
                freq = i.second;
            }
        }
        return ans;
    }
};