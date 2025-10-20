class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
            vector<int> v;
            for(int i = 0; i<n - 1; i++)
                v.push_back(weights[i] + weights[i + 1]);
            sort(v.begin(),v.end());
            long long ans = 0;
            for(int i = 0; i<k - 1; i++)
                ans += v[n - 2 - i] - v[i];
            return ans;
        }
    };