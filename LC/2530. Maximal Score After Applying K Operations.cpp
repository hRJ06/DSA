typedef long long ll;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto &i : nums) pq.push(i);
        ll ans = 0;
        while(k--) {
            int top = pq.top();
            pq.pop();
            ans += top;
            int x = ceil(top * 1.0 / 3);
            pq.push(x);
        }
        return ans;
    }
};