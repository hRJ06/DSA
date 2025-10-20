typedef long long ll;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<ll> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++)
            prefix[i] = nums[i] + prefix[i - 1];
        ll ans = -1;
        for(int i = 2; i<n; i++) 
            if(prefix[i - 1] > nums[i])
                ans = max(ans,prefix[i]);
        return ans;
    }
};