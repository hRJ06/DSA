class Solution {
private:
    int f(vector<int> &nums,int k) {
        int i = 0, ans = 0, n = nums.size();
        for(int j = 0; j<n; j++) {
            if(nums[j] & 1) k--;
            while(k < 0) {
                if(nums[i] & 1) k++;
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k - 1);
    }
};