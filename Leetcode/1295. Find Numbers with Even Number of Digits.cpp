class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int ans = 0;
            for(auto &i : nums) {
                string s = to_string(i);
                if(s.length() & 1) continue;
                ans++;
            }
            return ans;
        }
    };