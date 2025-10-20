class Solution {
public:
    int passThePillow(int n, int time) {
        int turn = time / (n - 1);
        return turn % 2 ? (n - time % (n - 1)) : (time % (n - 1) + 1);
    }
};