class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n % 2) return false;
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++) {
            int need = (k - (nums[i] % k)) % k;
            if(mp.count(need)) {
                mp[need]--;
                if(!mp[need]) mp.erase(need);
            }
            else {
                mp[nums[i] % k]++;
            }
        }
        return !mp.size();
    }
};