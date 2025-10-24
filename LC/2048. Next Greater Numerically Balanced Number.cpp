class Solution {
private:
    vector<int> store;
    bool check(vector<int> &count) {
        for(int d = 1; d<=7; d++) {
            if(count[d] != 0 and count[d] != d) return false;
        }
        return true;
    }
    void f(int num, int n, vector<int> &count) {
        if(num > n and check(count)) store.push_back(num);
        if(num > 1224444) return;
        for(int d = 1; d<=7; d++) {
            if(count[d] < d) {
                count[d] += 1;
                f(num * 10 + d, n, count);
                count[d] -= 1;
            }
        }
    }
public:
    int nextBeautifulNumber(int n) {
        vector<int> count(10, 0);
        f(0, n, count);
        sort(begin(store), end(store));
        return store[0];
    }
};