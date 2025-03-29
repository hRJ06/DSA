typedef long long ll;
class Solution {
private:
    int MOD = 1e9 + 7;
    vector<int> sieve(int n) {
        vector<int> v(n + 1, 1);
        for(int i = 2; i*i<=n; i++) { 
            if(v[i]) {
                for(int j = 2 * i; j<=n; j += i) {  
                    v[j] = 0;
                }
            }
        }
        vector<int> p;
        for(int i = 2; i<=n; i++) {
            if(v[i]) p.push_back(i);
        }
        return p;
    }
    vector<int> getPrimeScore(vector<int> &nums) {
        int limit = *max_element(begin(nums), end(nums)), n = nums.size();
        vector<int> primes = sieve(limit);
        vector<int> scores(n, 0);
        for(int i = 0; i<n; i++) {
            int num = nums[i];
            for(auto &j : primes) {
                if(ll(j) * (ll)j <= num) {  
                    if(!(num % j)) { 
                        scores[i]++;
                        while(!(num % j)) {
                            num /= j;
                        }
                    }
                }
                else 
                    break;
            }
            if(num > 1) {
                scores[i]++;
            }
        }
        return scores;
    }
    vector<int> findNextGE(vector<int> &v) {
        int n = v.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i = n - 1; i>=0; i--) {
            while(s.top() != -1 and v[s.top()] <= v[i]) { 
                s.pop();
            }
            ans[i] = s.top() != -1 ? s.top() : n;
            s.push(i);
        }
        return ans;
    }
    vector<int> findPrevGE(vector<int> &v) {
        int n = v.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i = 0; i<n; i++) {
            while(s.top() != -1 and v[s.top()] < v[i]) {  
                s.pop();
            }
            ans[i] = s.top() != -1 ? s.top() : -1;
            s.push(i);
        }
        return ans;
    }
    ll findPow(ll n, ll p) {
        ll ans = 1; 
        while(p > 0) { 
            if(p & 1) ans = (ans * n) % MOD; 
            p = p >> 1; 
            n = (n * n) % MOD; 
        } 
        return ans; 
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScores = getPrimeScore(nums);
        vector<int> nextGE = findNextGE(primeScores);
        vector<int> prevGE = findPrevGE(primeScores);
        vector<pair<int, int>> sorted;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            sorted.push_back({nums[i], i});
        }
        sort(begin(sorted), end(sorted), greater<>());
        int idx = 0;
        ll ans = 1; 
        while(k > 0) { 
            auto [num, i] = sorted[idx];
            ll left = i - prevGE[i];
            ll right = nextGE[i] - i;
            ll can_contribute = left * right;
            ll operations = min(can_contribute, (ll)k);
            k -= operations;
            ans = (ans * findPow(num, operations)) % MOD; 
            idx++;
        }
        return ans;
    }
};