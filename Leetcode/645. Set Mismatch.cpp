class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1,0);
        for(auto &i : nums) v[i]++;
        int a, b;
        for(int i = 1; i<=n; i++) {
            if(v[i] > 1) a = i;
            if(!v[i]) b = i;
        }
        return {a, b};
    }
};
