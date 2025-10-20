typedef long long ll;
class Solution {
private:
    int f(int n, vector<int> quantities, ll MAX) {
        /* N -> Shops */
        /* MAX - Maximum I can allocate to each shop */
        int length = quantities.size();
        int index = 0;
        for(int i = 0; i<n; i++) {
            if(index >= length) return true;
            quantities[index] -= min(1LL * quantities[index], MAX);
            if(!quantities[index]) index++;
        }
        return index >= length;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        /* A standard BS approach */
        ll total = accumulate(begin(quantities),end(quantities), 0LL);
        ll start = 1, end = total;
        int ans = -1;
        while(start <= end) {
            ll m = start + (end - start) / 2;
            if(f(n, quantities, m)) {
                ans = m;
                end = m - 1;
            }
            else start = m + 1;
        }
        return ans;
    }
};