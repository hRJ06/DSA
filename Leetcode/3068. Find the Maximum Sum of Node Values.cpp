typedef long long ll;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> benefit;
        ll org = 0;
        for(auto &i : nums) {
            org += i;
            benefit.push_back((i ^ k) - i);
        }
        sort(benefit.begin(),benefit.end(),greater<int>());
        int n = benefit.size();
        for(int i = 0; i<n - 1; i += 2) {
            ll pairSum = benefit[i] + benefit[i + 1];
            org += pairSum > 0 ? pairSum : 0;
        }
        return org;
    }
};