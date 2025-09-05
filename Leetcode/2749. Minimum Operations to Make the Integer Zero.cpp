typedef long long ll;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 1;
        while(true) {
            ll rem = num1 - 1LL * t * num2;
            if(rem < 0) return -1;
            if(__builtin_popcountll(rem) <= t and t <= rem) return t;
            t++;
        }
        return -1;
    }
};