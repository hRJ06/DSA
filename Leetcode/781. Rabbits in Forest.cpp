class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int, int> mp;
            for(auto &i : answers) mp[i]++;
            int ans = 0;
            for(auto &i : mp) {
                int x = i.first;
                int y = i.second;
                int groupSize = (x + 1);
                int group = ceil((y * 1.0) / groupSize);
                ans += (group * groupSize);
            }
            return ans;
        }
    };