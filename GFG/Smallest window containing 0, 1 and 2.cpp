class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int ans = INT_MAX;
        int n = S.length();
        int i = 0, j = 0;
        int z = 0, o = 0, t = 0;
        while(j < n) {
            if(S[j] == '0') z++;
            else if(S[j] == '1') o++;
            else t++;
            while(z and o and t) {
                ans = min(ans,j - i + 1);
                if(S[i] == '0') z--;
                else if(S[i] == '1') o--;
                else t--;
                i++;
            }
            j++;
        }
        return ans != INT_MAX ? ans : -1;
    }
};