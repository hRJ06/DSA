class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i<rows; i++) {
            for(int j = 1; j<cols; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        int ans = 0;
        for(int startCol = 0; startCol<cols; startCol++) {
            for(int j = startCol; j<cols; j++) {
                unordered_map<int,int> mp;
                mp.insert({0,1});
                int sum = 0;
                for(int i = 0; i<rows; i++) {
                    sum += matrix[i][j] - (startCol > 0 ? matrix[i][startCol  - 1] : 0);
                    int rem = sum - target;
                    if(mp.count(rem)) {
                        ans += mp[rem];
                    }
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};