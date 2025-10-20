class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s1, s2;
        for(auto &i : arr1) {
            string s = to_string(i), store = "";
            for(auto &j : s) {
                store += j;
                s1.insert(store);
            }
        }
        for(auto &i : arr2) {
            string s = to_string(i), store = "";
            for(auto &j : s) {
                store += j;
                s2.insert(store);
            }
        }
        int ans = 0;
        for(auto &i : s1) {
            if(s2.find(i) != s2.end() and i.length() > ans) 
                ans = i.length();
        }
        return ans;
    }
};