class Solution {
public:
    int findComplement(int num) {
        int n = log2(num) + 1;
        unsigned int mask = (1U << n) - 1;
        return mask ^ num;
    }
};
