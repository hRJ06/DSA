class Solution {
private:
    vector<int> bit;
    void addToCurrentWindow(int n) {
        for(int i = 0; i<32; i++) {
            bit[i] += (n >> i) & 1;
        }
    }
    void removeFromCurrentWindow(int n) {
        for(int i = 0; i<32; i++) {
            bit[i] -= (n >> i) & 1;
        }   
    }

    int getOrValue() {
        int ans = 0;
        for(int i = 0; i<32; i++) {
            if(bit[i] > 0)
                ans |= (1 << i);
        }
        return ans;
    }
    
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        bit.resize(32, 0);
        int i = 0, j = 0, ans = INT_MAX;
        while(j < n) {
            addToCurrentWindow(nums[j]);
            while(i <= j and getOrValue() >= k) {
                ans = min(ans, j - i + 1);
                removeFromCurrentWindow(nums[i]);
                i++;
            }
            j++;
        }
        return ans != INT_MAX ? ans : -1;
    }
};