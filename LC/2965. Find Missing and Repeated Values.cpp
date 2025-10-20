class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            unordered_map<int,int> mp;
            int a, b;
            for(auto &i : grid) {
                for(auto &j : i) {
                    mp[j]++;
                }
            }
            for(int i = 1; i<=pow(n,2); i++) {
                if(!mp.count(i)) {
                    b = i;
                }
                else if(mp[i] > 1) {
                    a = i;
                }
            }
            return {a,b};
        }
    };