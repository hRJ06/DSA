typedef long long ll;
class Solution {
public:
    ll countSubarrays(vector<int>& arr, int k) {
        int n = arr.size(), el = INT_MIN;
        for(auto &i : arr) el = max(el, i);
        int i = 0, j = 0;
        int count = 0;
        ll ans = 0;
        while(j < n) {
            if(arr[j] == el) count++;
            if(count >= k) {
                while(count >= k) {
                    ans += n - j;
                    if(arr[i] == el) count--;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
