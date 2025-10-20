class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = -1, length = INT_MIN;
        for(auto &i : dimensions) {
            int l = i[0], b = i[1];
            int diag = l * l + b * b;
            if(diag < length) continue;
            if(diag > length) {
                length = diag;
                ans = l * b; 
            }
            else ans = max(ans, l * b);
        }
        return ans;
    }
};