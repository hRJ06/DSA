class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i<n; i++) 
            prefix[i] = prefix[i - 1] ^ arr[i];
        vector<int> ans;
        for(auto &i : queries) {
            int l = i[0], r = i[1];
            if(l != 0) ans.push_back(prefix[r] ^ prefix[l - 1]);
            else ans.push_back(prefix[r]);
        }
        return ans;
    }
};