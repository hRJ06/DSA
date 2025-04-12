typedef long long ll;
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> s;
        int d = (n + 1) / 2;
        int start = pow(10, d - 1);
        int end = pow(10, d) - 1;
        for(int no = start; no<=end; no++) {
            string leftHalf = to_string(no);
            string full = "";
            if(!(n % 2)) {
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }
            else {
                string rightHalf = leftHalf.substr(0, d - 1);
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }
            ll num = stoll(full);
            if(num % k) continue;
            sort(full.begin(), full.end());
            s.insert(full);
        }
        vector<ll> factorial(11, 1);
        for(int i = 1; i<11; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        ll ans = 0;
        for(auto &st : s) {
            vector<int> count(10, 0);
            for(auto &ch : st) count[ch - '0']++;
            int totalDigits = st.length();
            int zero = count[0];
            int nonZero = totalDigits - zero;
            ll perm = nonZero * factorial[totalDigits - 1];
            for(int i = 0; i<10; i++) {
                perm /= factorial[count[i]];
            }
            ans += perm;
        }
        return ans;
    }
};