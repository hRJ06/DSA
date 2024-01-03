class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int ans = 0, prev = 0;
        for(int i = 0; i<m; i++) {
            int devices = count(bank[i].begin(),bank[i].end(),'1');
            if(devices > 0) {
                ans += devices * prev;
                prev = devices;
            }
        }
        return ans;
    }
};