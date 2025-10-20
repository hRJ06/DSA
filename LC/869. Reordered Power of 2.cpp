class Solution {
private:
    vector<int> f(int n) {
        vector<int> v(10, 0);
        while(n) {
            v[n % 10]++;
            n /= 10;
        }
        return v;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v = f(n);
        for(int i = 0; i<=29; i++) {
            vector<int> format = f(1 << i);
            if(v != format) continue;
            return true;
        }
        return false;
    }
};