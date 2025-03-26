class Solution {
    private:
        int f(int target, vector<int> &grid, int x) {
            int ans = 0;
            for(auto &i : grid) {
                int dif = abs(i - target);
                if(dif % x) return -1;
                ans += dif / x;
            }
            return ans;
        }
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m = grid.size(), n = grid[0].size();
            vector<int> store;
            for(auto &i : grid)
                for(auto &j : i)
                    store.push_back(j);
            sort(begin(store), end(store));
            int total = m * n;
            if(total & 1) {
                /* ODD */
                int median = store[total / 2];
                return f(median, store, x);
            }
            else {
                /* EVEN */
                int median_1 = store[total / 2];
                int median_2 = store[(total / 2) - 1];
                int ans_1 = f(median_1, store, x);
                int ans_2 = f(median_2, store, x);
                if(ans_1 != -1 and ans_2 != -1) return min(ans_1, ans_2);
                else if(ans_1 != -1) return ans_1;
                else if(ans_2 != -1) return ans_2;
                else return -1;
            }
            return -1;
        }
    };