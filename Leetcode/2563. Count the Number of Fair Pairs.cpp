typedef long long ll;
class Solution {
private:
    ll f(vector<int> &nums, int K) {
        int n = nums.size();
        ll ans = 0;
        for(int i = 0; i<n - 1; i++) {
            int s = i + 1, e = n - 1, index = -1;
            while(s <= e) {
                int m = s + (e - s) / 2;
                if(nums[m] + nums[i] >= K) {
                    index = m;
                    e = m - 1;
                }
                else s = m + 1;
            }
            ans += index != -1  ? n - index : 0;
        }
        return ans;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll find_l = f(nums, lower);
        ll find_u = f(nums, upper + 1);
        return abs(find_l - find_u);
    }
};