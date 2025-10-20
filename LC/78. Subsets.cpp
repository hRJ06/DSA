class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int)> f = [&](int i) -> void {
            if(i == n) {
                ans.push_back(cur);
                return;
            }
            f(i + 1);
            cur.push_back(nums[i]);
            f(i + 1);
            cur.pop_back();
        };
        f(0);
        return ans;

    }
};