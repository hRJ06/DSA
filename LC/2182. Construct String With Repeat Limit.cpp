typedef pair<char, int> p;
class Solution {
public:
    string repeatLimitedString(string s, int k) {
        unordered_map<char, int> mp;
        for(auto &i : s) {
            mp[i]++;
        }  
        priority_queue<p> pq;
        for(auto &i : mp) {
            pq.push({i.first, i.second});
        }
        string ans = "";
        while(!pq.empty()) {
            auto [c, cnt] = pq.top();
            pq.pop();
            int req = min(cnt, k);
            for(int i = 0; i<req; i++) {
                ans.push_back(c);
            }
            cnt -= req;
            if(cnt) {
                if(pq.empty()) break;
                auto [nc, ncnt] = pq.top();
                pq.pop();
                ans.push_back(nc);
                if(ncnt - 1) pq.push({nc, ncnt - 1});
                pq.push({c, cnt});
            }
        }
        return ans;
    }
};