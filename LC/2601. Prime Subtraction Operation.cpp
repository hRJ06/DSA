class Solution {
private:
    void generate_sieve(vector<int> &sieve, int n) {
        sieve[0] = sieve[1] = false;
        for(int i = 2; i<n; i++) {
            if(sieve[i]) {
                for(int j = 2 * i; j<n; j += i)
                    sieve[j] = false;
            }
        }
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        /* Start with a greedy approach */
        int n = nums.size();
        int N = 1e5;
        vector<int> sieve(N, true);
        generate_sieve(sieve, N);
        vector<int> primes;

        for(int i = 0; i<N; i++)
            if(sieve[i]) primes.push_back(i);

        for(int i = n - 2; i>=0; i--) {
            if(nums[i] < nums[i + 1]) continue;
            for(auto &p : primes) {
                if(p != nums[i] and (nums[i] - p > 0) and (nums[i] - p < nums[i + 1])) {
                    nums[i] -= p;
                    break;
                }
            }
        }

        for(auto &i : nums) cout << i << " ";
        for(int i = 1; i<n; i++) {
            if(nums[i] <= nums[i - 1]) return false;
        }

        return true;
    }
};