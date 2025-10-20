class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), c = 0;
        vector<int> mark(n, 0);
        for(int i = 1; i<n; i++) {
            if((nums[i] % 2) != (nums[i - 1] % 2)) mark[i] = c;
            else mark[i] = ++c;
        }
        int m = queries.size();
        vector<bool> ans;
        for(auto &i : queries) {
            int s = i[0], e = i[1];
            bool r = (mark[s] != mark[e]) ? false : true;
            ans.push_back(r);
        }
        return ans;
    }
};