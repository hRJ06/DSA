class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> v;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            v.push_back({i, nums[i]});
        }
        sort(v.begin(), v.end(), [&](pair<int,int> a, pair<int, int> b) {
            string n1 = to_string(a.second), n2 = to_string(b.second);
            int l1 = n1.length(), l2 = n2.length();
            for(int i = 0; i<l1; i++) {
                n1[i] = mapping[n1[i] - '0'] + '0';
            }
            for(int i = 0; i<l2; i++) {
                n2[i] = mapping[n2[i] - '0'] + '0';
            }
            int x = stoi(n1), y = stoi(n2);
            if(x != y) return x < y;
            return a.first < b.first;
        });
        vector<int> ans;
        for(auto &i : v) ans.push_back(i.second);
        return ans;
    }
};
