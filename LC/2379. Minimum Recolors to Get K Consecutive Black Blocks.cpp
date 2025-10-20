class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.length();
            int cur = 0, ans = INT_MAX;
            for(int i = 0; i<k; i++) {
                if(blocks[i] != 'B') cur++;
            }
            ans = cur;
            for(int i = 0, j = k; j<n; i++, j++) {
                if(blocks[i] != 'B') cur--;
                if(blocks[j] != 'B') cur++; 
                ans = min(ans, cur);
            }
            return ans;
        }
    };
    