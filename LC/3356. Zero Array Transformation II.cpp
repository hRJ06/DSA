class Solution {
    private:
        int f(int K, vector<int> &nums, vector<vector<int>> &q) {
            int n = nums.size();
            vector<int> v(n + 1, 0);
            for(int i = 0; i<K; i++) {
                int l = q[i][0], r = q[i][1] + 1, val = q[i][2];
                v[l] += val;
                v[r] -= val;
            }
            for(int i = 1; i<n; i++) {
                v[i] = v[i - 1] + v[i];
            }
            for(int i = 0; i<n; i++) {
                if(nums[i] > v[i]) return false;
            }
            return true;
        }
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            /* 
                Intuition is simple that if I can solve using K queries, I can solve using K + 1 as well.
                So, clear idea of monotic search space
            */
            int s = 0, e = queries.size();
            int ans = -1;
            while(s <= e) {
                int m = s + (e - s) / 2;
                if(f(m, nums, queries)) {
                    ans = m;
                    e = m - 1;
                }
                else s = m + 1;
            }
            return ans;
        }
    };