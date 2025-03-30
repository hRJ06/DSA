class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> mp;
            int n = s.length();
            for(int i = 0; i<n; i++) {
                mp[s[i]] = i;
            }
            vector<int> ans;
            int start = 0, maxi = INT_MIN;
            for(int i = 0; i<n; i++) {
                maxi = max(maxi, mp[s[i]]);
                if(i == maxi) {
                    ans.push_back(i - start + 1);
                    start = i + 1;
                }
            }
            return ans;
        }
    };