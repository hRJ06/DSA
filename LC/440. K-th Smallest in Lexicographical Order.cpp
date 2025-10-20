class Solution {
private:
    int find(long cur, long next, int n) {
        int ans = 0;
        while(cur <= n) {
            int between = next - cur;
            ans += between;
            cur *= 10;
            next = min(next * 10, long(n + 1));
        }
        return ans;
    }
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k > 0) {
            int count = find(cur, cur + 1, n);
            if(count <= k) {
                cur++;
                k -= count;
            }
            else {
                cur *= 10;
                k -= 1;
            }
        }   
        return cur;
    }
};