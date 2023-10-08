class Solution {
public:
    int differenceOfSums(int n, int m) {
        int a = 0, b = 0;
        for(int i = 1; i<=n; i++) {
            if(i % m) b += i;
            else a += i;
        }
        return b - a;
    }
};