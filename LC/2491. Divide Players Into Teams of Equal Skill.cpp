class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long ans = 0;
        int res = skill[0] + skill.back();
        for(int i = 0; i<n/2; i++) 
            if(skill[i] + skill[n - i - 1] != res) return -1;
            else ans += skill[i] * skill[n - i - 1];
        return ans;
    }
};