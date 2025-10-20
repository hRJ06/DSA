class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 and k == 1) return 0;
        int m = pow(2,n - 1) / 2;
        return k <= m ? kthGrammar(n - 1,k) : !kthGrammar(n,k - m);
    }
};