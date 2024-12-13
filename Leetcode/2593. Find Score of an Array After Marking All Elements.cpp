typedef long long ll;
class c {
public:
    bool operator()(const pair<int, int> &p, const pair<int, int> &q) const {
        if (p.first != q.first) return p.first < q.first;
        return p.second < q.second;
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int, int>, c> s;
        int n = nums.size();
        for(int i = 0; i<n; i++) s.insert({nums[i], i});
        ll ans = 0;
        while(!s.empty()) {
            auto [val, ind] = *(s.begin());
            s.erase(s.begin());
            ans += val;
            if(ind + 1 < n) s.erase({nums[ind + 1], ind + 1});
            if(ind - 1 >= 0) s.erase({nums[ind - 1], ind - 1});
        }
        return ans;
    }
};
