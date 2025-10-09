typedef long long ll;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = mana.size(), n = skill.size();
        vector<ll> time(n, 0);
        for(int i = 0; i<m; i++) {
            time[0] += mana[i] * skill[0];
            for(int j = 1; j<n; j++) {
                time[j] = max(time[j - 1], time[j]) + (1LL * mana[i] * skill[j]);
            }
            for(int j = n - 1; j>0; j--) {
                time[j - 1] = time[j] - (1LL * mana[i] * skill[j]);
            }
        }
        return time[n - 1];
    }
};