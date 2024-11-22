class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        /* 
            Brute force idea is to count number of rows that are same or inverted as the current row.
        */   
        int ans = 1;
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string,int> mp;
        for(int i = 0; i<m; i++) {
            string s = "", inverted = "";
            for(int j = 0; j<n; j++) {
                s += matrix[i][j] ? "1" : "0";
                inverted += matrix[i][j] ? "0" : "1";
            }
            ans = max(ans, 1 + mp[s] + mp[inverted]);
            mp[s]++;
        }
        return ans;
    }
};