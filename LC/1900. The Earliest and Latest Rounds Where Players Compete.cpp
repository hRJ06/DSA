class Solution {
private:
    int a = INT_MAX, b = INT_MIN;
    void f(vector<int> &v, int round, int fP, int sP) {
        int n = v.size();
        int new_n = (n + 1) / 2;
        bool f1 = false, f2 = false;
        for(int i = 0; i<new_n; i++) {
            if(v[i] == fP and v[n - i - 1] == sP) {
                a = min(a, round);
                b = max(b, round);
                return;
            }
            if(v[i] == fP || v[n - i - 1] == fP) f1 = true;
            if(v[i] == sP || v[n - i - 1] == sP) f2 = true;
        }
        if(!f1 or !f2) return;
        vector<int> new_v(new_n);
        int c = (1 << new_n);
        for(int i = 0; i<c; i++) {
            /* i -> Combination Number */
            int left = 0, right = new_n - 1;
            for(int j = 0; j<new_n; j++) {
                if((1 << j) & i) new_v[left++] = v[j];
                else new_v[right--] = v[n - j - 1];
            }
            f(new_v, round + 1, fP, sP);
        }
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        /* 
            n -> (n + 1) / 2 (L)
            L -> 2^L
            L combination(s) of size (n + 1) / 2
        */
        vector<int> v(n);
        for(int i = 1; i<=n; i++) v[i - 1] = i;
        f(v, 1, firstPlayer, secondPlayer);
        return {a != INT_MAX ? a : 1, b != INT_MIN ? b : 1};
    }
};