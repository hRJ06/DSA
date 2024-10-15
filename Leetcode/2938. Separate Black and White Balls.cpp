class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int count = 0,  j = s.length() - 1;
        while(j >= 0) {
            while(j >= 0 and s[j] != '1') {
                j--;
                count++;
            }
            if(j >= 0) ans += count;
            j--;
        }
        return ans;
    }
};