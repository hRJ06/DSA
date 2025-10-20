class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> v(n + 1, 0);
        for(auto &i : shifts) {
            int s = i[0], e = i[1];
            if(i[2]) {
                v[s] += 1;
                v[e + 1] -= 1;
            }
            else {
                v[s] -= 1;
                v[e + 1] += 1;
            }
        }
        for(int i = 1; i<v.size(); i++) {
            v[i] += v[i - 1];
        }
        for(int i = 0; i<v.size() - 1; i++) {
            int offset = v[i] % 26;  
            if(offset < 0) offset += 26;
            s[i] = 'a' + (s[i] - 'a' + offset) % 26;
        }
        return s;
    }
};