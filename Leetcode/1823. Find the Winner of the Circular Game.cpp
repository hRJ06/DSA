class Solution {
private:
    int f(int index,int k,vector<int> &v) {
        int n = v.size();
        if(n <= 1) return v[0];
        index = (index + k - 1) % n;
        v.erase(v.begin() + index);
        return f(index, k, v);
    }
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i = 0; i<n; i++) v[i] = i + 1;
        return f(0,k,v);
    }
};
