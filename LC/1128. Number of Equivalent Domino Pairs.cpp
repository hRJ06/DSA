class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<pair<int, int>, int> mp;
            int ans = 0;
            for(auto &i : dominoes) {
                ans += mp[{i[0], i[1]}];
                if(i[0] != i[1]) ans += mp[{i[1], i[0]}];
                mp[{i[0], i[1]}]++;
            }
            return ans;
        }
    };