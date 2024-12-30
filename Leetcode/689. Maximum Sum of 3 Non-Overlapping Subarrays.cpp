class Solution {
private:
    vector<vector<int>> dp;
    int g(int i, int count, int k, vector<int> &v) {
        if(!count) return 0;
        if(i >= v.size()) return INT_MIN;
        if(dp[i][count] != -1) return dp[i][count];
        int a = v[i] + g(i + k, count - 1, k, v);
        int b = g(i + 1, count, k, v);
        return dp[i][count] = max(a, b);
    }
    void f(int index, int count, int k, vector<int> &v, vector<int> &ans) {
        if(!count) return;
        if(index >= v.size()) return;
        int a = v[index] + g(index + k, count - 1, k, v);
        int b = g(index + 1, count, k, v);
        if(a >= b) {
            ans.push_back(index);
            f(index + k, count - 1, k, v, ans);
        }
        else 
            f(index + 1, count, k, v, ans);
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        vector<int> v;
        for(int i = 0; i<k; i++) {
            sum += nums[i];
        }
        v.push_back(sum);
        for(int i = 0, j = k; j<n; i++, j++) {
            sum -= nums[i];
            sum += nums[j];
            v.push_back(sum);
        }
        dp.resize(n, vector<int>(4, -1));
        vector<int> ans;
        f(0, 3, k, v, ans);
        return ans;
    }
};