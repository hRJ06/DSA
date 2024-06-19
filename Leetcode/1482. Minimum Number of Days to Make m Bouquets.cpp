class Solution {
private:
    bool possible(vector<int>& bloomDay, int m, int k, int mid) {
        int count = 0, bouquets = 0;
        for(auto &i : bloomDay) {
            if(i <= mid) count++;
            else count = 0;
            if(count >= k) {
                count = 0;
                bouquets++;
            }
        }
        return bouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(possible(bloomDay, m, k, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};