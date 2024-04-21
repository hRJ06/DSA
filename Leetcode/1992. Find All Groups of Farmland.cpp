class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size(), n = land[0].size();
        int dir[5] = {-1,0,1,0,-1};
        function<void(int,int,int&,int&)> f = [&](int i,int j,int &er,int &ec) -> void {
            if(i < 0 or j < 0 or i == m or j == n or !land[i][j]) return;
            land[i][j] = 0;
            er = max(er,i);
            ec = max(ec,j);
            for(int k = 0; k<4; k++)
                f(i + dir[k],j + dir[k + 1],er,ec);
        };
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(land[i][j]) {
                    int er = i, ec = j;
                    f(i,j,er,ec);
                    ans.push_back({i,j,er,ec});
                }
            }
        }
        return ans;
    }
};