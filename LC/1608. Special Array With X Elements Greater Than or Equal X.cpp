class Solution {
private:
    bool f(int i,vector<int> &nums) {
        int store = i;
        for(auto &ele : nums) {
            if(ele >= i) store--;
            if(store < 0) return false;
        }
        return !store;
    }
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<=n; i++) {
            if(f(i,nums)) return i;
        }
        return -1;
    }
};