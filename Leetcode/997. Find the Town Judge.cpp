class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> ind;
        for(auto &i : trust) {
            mp[i[0]].push_back(i[1]);
            ind[i[1]]++;       
        }
        bool found = false;
        int judge = -1;
        for(int i = 1; i<=n; i++) {
            if(!mp.count(i) and ind[i] == n - 1) {
                if(found) return -1;
                else {
                    found = true;
                    judge = i;
                }
            }
        }
        return judge;
    }
};