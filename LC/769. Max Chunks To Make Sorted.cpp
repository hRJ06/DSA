class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n), suffix(n);
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i<n; i++) {
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[n - i - 1]);
            prefix[i] = maxi;
            suffix[n - i - 1] = mini;
        }
        int ans = 1;
        for(int i = 1; i<n; i++) {
            if(prefix[i - 1] < suffix[i]) ans++;
        }
        return ans;
    }
};