class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 0; i<31; i++) {
            int bit_a = (start >> i) & 1;
            int bit_b = (goal >> i) & 1;
            if(bit_a != bit_b) ans++;
        }
        return ans;
    }
};