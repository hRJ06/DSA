class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "", target = "123450";
        for(auto &i : board) 
            for(auto &j : i)
                start += j + '0';
        queue<string> q;
        q.push(start);
        unordered_map<int, vector<int>> mp{{0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{3,5,1}},{5,{4,2}}};
        unordered_map<string, bool> vis;
        int ans = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                string top = q.front();
                q.pop();
                if(top != target) {
                    int index = -1;
                    for(int i = 0; i<6; i++) 
                        if(top[i] == '0') index = i;
                    vector<int> swaps = mp[index];
                    for(auto &sw : swaps) {
                        string store = top;
                        swap(store[index], store[sw]);
                        if(!vis[store]) q.push(store);
                        vis[store] = true;
                    }
                }
                else 
                    return ans;
            }
            ans++;
        }
        return -1;
    }
};