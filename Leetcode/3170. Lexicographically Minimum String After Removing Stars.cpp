class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.first != b.first) return a.first > b.first;
        else return a.second < b.second;
    }
};
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int n = s.length();
        for(int i = 0; i<n; i++) {
            if(s[i] != '*') {
                pq.push({s[i], i});
            }
            else {
                if(!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    s[top.second] = '*'; /* Delimeter */
                }
            }
        }
        string ans = "";
        for(auto &i : s) {
            if(i != '*') ans.push_back(i);
        }
        return ans;
    }
};