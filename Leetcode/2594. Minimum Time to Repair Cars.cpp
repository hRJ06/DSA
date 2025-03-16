typedef long long ll;
class Solution {
private:
    bool f(ll mid, vector<int> &ranks, int cars) {
        ll count = 0;
        for(auto &i : ranks) {
            count += (int)sqrt(mid / i);
        }
        return count >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll start = 1, end = end = (ll)*min_element(ranks.begin(), ranks.end()) * (ll)cars * cars, ans = -1;
        while(start <= end) {
            ll mid = start + (end - start) / 2;
            if(f(mid, ranks, cars)) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};