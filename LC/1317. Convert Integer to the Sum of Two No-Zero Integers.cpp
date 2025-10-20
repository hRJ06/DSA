class Solution {
private:
    bool f(int a) {
        while(a) {
            int dig = a % 10;
            if(!dig) return false;
            a /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i<n; i++) {
            if(f(i) and f(n - i)) return {i, n - i};
        }
        return {};
    }
};