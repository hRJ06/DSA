class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(auto &i : logs) {
            if(i == "../") {
                if(s.empty()) continue;
                else s.pop();
            }
            else if(i == "./") continue;
            else s.push(i);
        }
        return s.size();
    }
};
