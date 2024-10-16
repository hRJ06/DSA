class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        int total = a + b + c;
        string ans = "";
        for(int i = 0; i<total; i++) {
            auto top = pq.top();
            pq.pop();
            int count = top.first;
            char ch = top.second;
            if(ans.size() >= 2 and ans.back() == ch and ans[ans.size() - 2] == ch) {
                if(pq.empty()) break;
                auto second_top = pq.top();
                pq.pop();
                int second_count = second_top.first;
                char second_ch = second_top.second;
                ans += second_ch;
                second_count--;
                if(second_count > 0) pq.push({second_count, second_ch});
                pq.push({count, ch});
            }
            else {
                ans += ch;
                count--;
                if(count > 0) pq.push({count, ch});
            }
        }
        return ans;
    }
};