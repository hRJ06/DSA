class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>> range(n);
        for(int i = 0; i<n; i++) {
            int left = max(0,i - gallery[i]);
            int right = min(n - 1,i + gallery[i]);
            range[i] = {left,right};
        }
        sort(range.begin(),range.end());
        int start = 0, i = 0, ans = 0;
        while(start <= n - 1) {
            int end = INT_MIN;
            while(i < n and range[i].first <= start) {
                end = max(end,range[i].second);
                i++;
            }
            if(end != INT_MIN) {
                start = end + 1;
                ans++;
            }
            else
                return -1;
        }
        return ans;
    }
};