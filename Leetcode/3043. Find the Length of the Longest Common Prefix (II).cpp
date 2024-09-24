class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        int n = arr1.size();
        for(int i = 0; i<n; i++) {
            string s = to_string(arr1[i]);
            int m = s.length();
            string prefix = "";
            for(int j = 0; j<m; j++) {
                prefix += s[j];
                st.insert(prefix);
            }
        }
        int ans = 0;
        n = arr2.size();
        for(int i = 0; i<n; i++) {
            string s = to_string(arr2[i]);
            int m = s.length();
            string prefix = "";
            for(int j = 0; j<m; j++) {
                prefix += s[j];
                if(st.find(prefix) != st.end()) ans = max(ans, j + 1);
            }
        }
        return ans;
    }
};
