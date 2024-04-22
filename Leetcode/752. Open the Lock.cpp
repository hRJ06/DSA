class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSets(deadends.begin(),deadends.end());
        if(deadSets.count("0000")) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        unordered_set<string> v;
        v.insert("0000");
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            string s = top.first;
            int move = top.second;
            if(s != target) {
                for(int i = 0; i<4; i++) {
                    for(auto &j : {-1, 1}) {
                        int newDigit = (s[i] - '0' + j + 10) % 10;
                        string newS = s;
                        newS[i] = newDigit + '0';
                        if(v.find(newS) == v.end() and deadSets.find(newS) == deadSets.end()) {
                            v.insert(newS);
                            q.push({newS,move + 1});
                        }
                    }
                }
            }
            else 
                return move;
        }
        return -1;
    }
};