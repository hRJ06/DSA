typedef long long ll;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = 0, sum = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i<k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }
        if(mp.size() == k) ans = max(ans, sum);
        for(int i = 0, j = k; j<n; i++, j++) {
            mp[nums[i]]--;
            if(!mp[nums[i]]) mp.erase(nums[i]);
            sum -= nums[i];
            sum += nums[j];
            mp[nums[j]]++;
            if(mp.size() == k) ans = max(ans, sum);
        }
        return ans;
    }
};