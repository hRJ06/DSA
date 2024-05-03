class Solution {
private:
    vector<int> split(string &s,char ch) {
        vector<int> ans;
        int start = 0;
        int end = s.find(ch,start);
        while(end != string::npos) {
            string store = s.substr(start,end - start);
            ans.push_back(stoi(store));
            start = end + 1;
            end = s.find(ch,start);
        }
        string store = s.substr(start,end - start);
        ans.push_back(stoi(store));
        return ans;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1,'.');
        vector<int> v2 = split(version2,'.');
        for(int i = 0; i<max(v1.size(),v2.size()); i++) {
            int val1 = i < v1.size() ? v1[i] : 0;
            int val2 = i < v2.size() ? v2[i] : 0;
            if(val1 < val2) return -1;
            if(val1 > val2) return 1;
        }
        return 0;
    }
};