class Solution {
public:
    int smithNum(int n) {
        // code here
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i<=sqrt(n); i++) {
            if(isPrime[i]) {
                for(int j = 2 * i; j<=n; j += i)
                    isPrime[j] = false;
            }
        }
        if(!(isPrime[n])) {
            int store = n;
            int a = 0;
            while(store) {
                a += (store % 10);
                store /= 10;
            }
            vector<int> pf;
            for(int i = 2; i<=n; i++) {
                while(isPrime[i] and !(n % i)) {
                    pf.push_back(i);
                    n /= i;
                }
            }
            int b = 0;
            for(auto &i : pf) {
                int m = i, sum = 0;
                while(m) {
                    sum += m % 10;
                    m /= 10;
                }
                b += sum;
            }
            return a == b;
        }
        return 0;
    }
};