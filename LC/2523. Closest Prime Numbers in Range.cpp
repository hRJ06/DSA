class Solution {
    private:
        void f(vector<int> &sieve, int n) {
            sieve[0] = sieve[1] = false;
            for(int i = 0; i<n; i++) {
                if(sieve[i]) {
                    for(int j = 2 * i; j<n; j+=i) {
                        sieve[j] = false;
                    }
                }
            }
        }
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> sieve(right + 1, true);
            f(sieve, right + 1);   
            vector<int> p;
            for(int i = left; i<=right; i++) {
                if(sieve[i]) p.push_back(i);
            }
            int n = p.size();
            if(n <= 1) return {-1, -1};
            int ans = INT_MAX, a, b;
            for(int i = 0; i<n - 1; i++) {
                int diff = p[i + 1] - p[i];
                if(diff < ans) {
                    ans = diff;
                    a = p[i];
                    b = p[i + 1];
                }
            }
            return {a, b};
        }
    };