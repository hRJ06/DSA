class Solution {
private:
    bool f(vector<int> &position,int mid,int m,int n) {
        int count = 1, prev = 0;
        for(int i = 1; i<n; i++) {
            if(position[i] - position[prev] >= mid) {
                count++;
                prev = i;
            }
        }
        return count >= m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = *max_element(position.begin(), position.end());
        int ans = -1,n = position.size();
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(f(position, mid, m, n)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};