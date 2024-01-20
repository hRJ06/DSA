class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        vector<int> left(n,0), right(n,0);
        stack<pair<int,int>> s1,s2;
        for(int i = 0; i<n; i++) {
            int count = 1;
            while(!s1.empty() and s1.top().first > arr[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i],count});
            left[i] = count;
        }
        for(int i = n - 1; i>=0; i--) {
            int count = 1;
            while(!s2.empty() and s2.top().first >= arr[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i],count});
            right[i] = count;
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = (ans + (arr[i] * 1LL * (left[i] * right[i]) % MOD) %MOD) % MOD;
        }
        return ans;
    }
};