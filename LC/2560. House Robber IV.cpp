class Solution {
    private:
        bool f(vector<int> &v, int m, int k) {
            int count = 0;
            for(int i = 0; i<v.size(); i++) {
                if(v[i] <= m) {
                    count++;
                    i++;
                }
            }
            return count >= k;
        }
    public:
        int minCapability(vector<int>& nums, int k) {
            int l = 1, r = *max_element(begin(nums), end(nums));
            int ans = -1;
            while(l <= r) {
                int m = l + (r - l) / 2;
                if(f(nums, m, k)) {
                    ans = m;
                    r = m - 1;
                }
                else l = m + 1;
            }
            return ans;
        }
    };