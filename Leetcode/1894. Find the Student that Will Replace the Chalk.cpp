typedef long long ll;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll total = accumulate(chalk.begin(), chalk.end(), 0LL);
        ll left = k % total;
        int n = chalk.size();
        for(int i = 0; i<n; i++) {
            if(chalk[i] > left) return i;
            left -= chalk[i];
        }
        return -1;
    }
};