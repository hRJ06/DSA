class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookies = s.size(), greed = g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i,j;
        for(i = 0, j = 0; i<greed and j<cookies; j++) {
            if(g[i] <= s[j]) i++;
        }
        return i;
    }
};