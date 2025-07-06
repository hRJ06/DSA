class FindSumPairs {
private:
    vector<int> v1, v2;
    unordered_map<int, int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for(auto &i : nums2) mp[i]++;
    }
    
    void add(int index, int val) {
        mp[v2[index]]--;
        v2[index] += val;
        mp[v2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto &i : v1) ans += mp[tot - i];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */