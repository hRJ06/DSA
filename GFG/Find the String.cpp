class Solution {
public:
    string findString(int n, int k) {
        string ans(n, '0');
        string temp = ans;
        unordered_map<string, int> mp;
        mp[temp] = 1;
        dfs(temp, ans, mp, k);
        return ans;
    }

private:
    void dfs(string curr,string &ans,unordered_map<string, int> &mp, int k) {
        string temp;
        for(int i = k - 1; i>=0; i--) {
            temp = curr.substr(1); 
            temp.push_back(i + '0');
            if(mp.find(temp) == mp.end()) {
                mp[temp] = 1;
                ans.push_back(i + '0');
                dfs(temp, ans, mp, k);
                return;
            }
        }
    }
};