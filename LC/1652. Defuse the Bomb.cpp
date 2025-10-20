class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(!k) return vector<int>(n, 0);
        vector<int> ans(n);
        if(k > 0) {
            for(int i = 0; i<n; i++) {
                int sum = 0, start_index = i + 1;
                for(int count = 0; count<k; count++, start_index++) {
                    sum += code[start_index % n];
                }
                ans[i] = sum;
            }
            return ans;
        }
        k = abs(k);
        for(int i = 0; i<n; i++) {
            int sum = 0, start_index = i - 1;
            for(int count = 0; count<k; count++, start_index--) {
                sum += code[start_index >= 0 ? start_index : start_index + n];
            }
            ans[i] = sum;
        }
        return ans;
    }
};