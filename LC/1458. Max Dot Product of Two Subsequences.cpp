class Solution {
private:
    int f(int i,int j,vector<int> &a,vector<int> &b,int n,int m,vector<vector<int>> &dp) {
        if(i >= n or j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int x = f(i + 1,j,a,b,n,m,dp);
        int y = f(i,j + 1,a,b,n,m,dp);
        int z = (a[i] * b[j]) + f(i + 1,j + 1,a,b,n,m,dp);
        return dp[i][j] = max({x,y,z});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int fM = INT_MIN,fm = INT_MAX,sM = INT_MIN,sm = INT_MAX;
        for(auto &i : nums1) {
            fM = max(fM,i);
            fm = min(fm,i);
        }
        for(auto &i : nums2) {
            sM = max(sM,i);
            sm = min(sm,i);
        }
        if((fM < 0 and sm > 0) or (sM < 0 and fm > 0)) return max(fM * sm,sM * fm);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0,0,nums1,nums2,n,m,dp);
    }
};