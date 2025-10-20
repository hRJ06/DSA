class Solution {
private:
    int f(vector<int> &nums,int i,int k,unordered_map<int,int> &mp) {
        if(i >= nums.size()) return 1;
        int ans = 0;
        if(!mp[nums[i] - k] and !mp[nums[i] + k]) {
            mp[nums[i]]++;
            ans = f(nums,i + 1,k,mp);
            mp[nums[i]]--;
        }
        ans += f(nums,i + 1,k,mp);
        return ans;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = f(nums,0,k,mp);
        return ans - 1;
    }
};