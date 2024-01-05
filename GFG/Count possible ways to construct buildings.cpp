class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int MOD = 1e9 + 7;
        vector<long long> fib(N + 1, 0);
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i<=N; i++) {
            fib[i] = (fib[i - 1] % MOD + fib[i - 2] % MOD) % MOD;
        }
        
        return ((fib[N] * fib[N]) % MOD);
	}
};