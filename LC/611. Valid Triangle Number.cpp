class Solution {
private:
    int f(int start, int end, vector<int> &nums, int total) {
        int ans = -1;
        while(start <= end) {
            int m = start + (end - start) / 2;
            if(nums[m] < total) {
                ans = m;
                start = m + 1;
            }
            else end = m - 1;
        }
        return ans;
    }
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0, n = nums.size();
        for(int i = 0; i<n - 2; i++) {
            for(int j = i + 1; j<n - 1; j++) {
                int total = nums[i] + nums[j];
                int count = f(j + 1, n - 1, nums, total);
                if(count != -1) ans += count - j;
            }
        }
        return ans;
    }
};