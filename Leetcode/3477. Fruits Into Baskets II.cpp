class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = n;
        vector<int> used(n, false);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(!used[j] and baskets[j] >= fruits[i]) {
                    used[j] = true;
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};