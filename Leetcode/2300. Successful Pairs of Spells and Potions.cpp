class Solution {
private:
    int f(int spell, vector<int> &potions, long long success) {
        int n = potions.size();
        int start = 0, end = n - 1, index = -1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(1LL * potions[mid] * spell >= success) {
                index = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return index != -1 ? n - index : 0;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        vector<int> ans;
        for(auto &i : spells) {
            int count = f(i, potions, success);
            ans.push_back(count);
        }
        return ans;
    }
};