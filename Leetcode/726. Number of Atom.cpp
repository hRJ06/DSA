class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string,int>> s;
        int n = formula.length();
        for(int i = 0; i<n; i++) {
            if(formula[i] == '(') 
                s.push({"(", 1});
            else if(isupper(formula[i])) {
                // Atom
                string store(1, formula[i]); 
                while(i + 1 < n and islower(formula[i + 1])) {
                    store += formula[++i];
                }
                // no
                int count = 0;
                while(i + 1 < n and isdigit(formula[i + 1])) {
                    count = (count * 10) + formula[++i] - '0';
                }
                s.push({store, !count ? 1 : count});
            }
            else {
                // ')'
                int count = 0;
                while(i + 1 < n and isdigit(formula[i + 1])) {
                    count = (count * 10) + formula[++i] - '0';
                }
                // Need to pop '(' in any case, hence need to traverse
                if(!count) count = 1;
                vector<pair<string,int>> v;
                while(!s.empty() and s.top().first != "(") {
                    auto top = s.top();
                    s.pop();
                    v.push_back({top.first, top.second * count});
                }
                s.pop(); // '('
                for(auto &i : v) s.push(i);
            }
        }  
        map<string,int> mp;
        while(!s.empty()) {
            auto top = s.top();
            mp[top.first] += top.second;
            s.pop();
        }
        string ans = "";
        for(auto &i : mp) {
            ans += i.first;
            if(i.second > 1) ans += to_string(i.second);
        }
        return ans;
    }
};  
