class Solution {
public:
    int pivotInteger(int n) {
        int total =( n * (n + 1)) / 2;
        for(int i = 1; i<=n; i++) {
            int store = (i * (i + 1)) / 2;
            if(store != total - store + i) continue;
            else return i;
        }
        return -1;
    }
};