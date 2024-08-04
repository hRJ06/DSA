typedef pair<int,int> p;
class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<p, vector<p>, greater<p>> pq;
        for(int i = 0; i<n; i++) {
            pq.push({nums[i], i});
        }
        int ans = 0;
        for(int i = 1; i<=right; i++) {
            auto top = pq.top();
            pq.pop();
            int total = top.first, index = top.second;
            if(i >= left) { 
                ans = (ans + total) % MOD;
            }
            int n_index = index + 1;
            if(n_index < n) {
                pq.push({total + nums[n_index], n_index});
            }
        }   
        return ans;
    }
};
