typedef long long ll;
class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        ll t1 = accumulate(a.begin(), a.end(), 0LL);
        ll t2 = accumulate(b.begin(), b.end(), 0LL);
        ll z1 = count(a.begin(), a.end(), 0);
        ll z2 = count(b.begin(), b.end(), 0);
        if(!z1 and z2 and t1 >= t2 + z2) return t1;
        else if(!z2 and z1 and t2 >= t1 + z1) return t2;
        else if (!z1 and !z2 and t1 == t2) return t1;
        else if (z1 and z2) return max(t1 + z1, t2 + z2);
        return -1;
    }
};
