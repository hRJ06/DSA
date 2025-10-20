typedef long long ll;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        priority_queue<int> maxPQ;
        ll left = 0, right = 0;
        int n = nums.size();
        int size = (n / 3);
        int left_size = 2 * size;
        vector<ll> l, r;
        for(int i = 0; i<left_size; i++) {
            left += nums[i];
            maxPQ.push(nums[i]);
            if(maxPQ.size() > size) {
                left -= maxPQ.top();
                maxPQ.pop();
            }
            if(i >= size - 1) l.push_back(left);
        }
        for(int i = n - 1; i>=size; i--) {
            right += nums[i];
            minPQ.push(nums[i]);
            if(minPQ.size() > size) {
                right -= minPQ.top();
                minPQ.pop();
            }
            if(i <= left_size) r.push_back(right);
        }
        ll ans = LLONG_MAX;
        for(int i = 0; i<=size; i++) {
            ans = min(ans, ll(l[i] - r[size - i]));
        }
        return ans;
    }
};