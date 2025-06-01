typedef long long ll;
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        ll ans = 0;
        for(int i = 0; i<=min(n, limit); i++) {
            int rem = n - i;
            if(rem > 2 * limit) continue;
            int mini = max(0, rem - limit);
            int maxi = min(rem, limit);
            ans += (maxi - mini) + 1;
        }
        return ans;
    }
};