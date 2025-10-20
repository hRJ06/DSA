class Solution {
private:
    int f(int x,unordered_map<int,int> &mp) {
        int group = 0;
        for(auto &[_,f] : mp) {
            int a = f / (x + 1);
            int b = f % (x + 1);
            if(!b) group += a;
            else if((x - b) <= a) group += a + 1;
            else return -1;
        }
        return group;
    }
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> mp;
        int freq = INT_MAX;
        for(auto &i : nums) mp[i]++;
        for(auto &[_,f] : mp) freq = min(freq,f);  
        int ans = INT_MAX;
        for(int i = 1; i<=freq; i++) {
            int store = f(i,mp);
            if(store != -1) ans = min(ans,store);
        }
        return ans;
    }
};