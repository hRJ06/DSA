class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> s(folder.begin(), folder.end());
        vector<string> ans;
        for(auto &i : folder) {
            string store = "/";
            int len = i.length();
            bool flag = true;
            for(int j = 1; j<len; j++) {
                store += i[j];
                if(j + 1 < len and i[j + 1] == '/') {
                    if(s.find(store) != s.end()) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};