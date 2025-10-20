class Solution {
    private:
        bool helper(int i,int k,vector<int> &nums,vector<vector<int>> &dp) {
            if(!k) return true;
            if(!i) return nums[0] == k;
            if(dp[i][k] != -1) return dp[i][k];
            bool a = helper(i - 1,k,nums,dp);
            bool b = false;
            if(nums[i] <= k)
                b = helper(i - 1,k - nums[i],nums,dp);
            return dp[i][k] = a or b;
        }
    public:
        bool canPartition(vector<int>& nums) {
            int total = accumulate(nums.begin(),nums.end(),0);
            if(total % 2) return false;
            int k = total / 2;
            int n = nums.size();
            vector<vector<int>> dp(n,vector<int>(k + 1,-1));
            return helper(n - 1,k,nums,dp);
        }
    };