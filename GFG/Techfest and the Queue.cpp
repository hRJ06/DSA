
class Solution {
private:
    int f(int n) {
        int ans = 0;
        int store = n;
        for(int i = 2; i<=ceil(sqrt(n)); i++) {
            while(!(store % i)) {
                ans += 1;
                store /= i;
            }
        }
        if(store != 1) 
            ans += 1;
        return ans;
    }
public:
    int sumOfPowers(int a, int b) {
        int ans = 0;
        for(int i = a; i<=b; i++) {
            ans += f(i);
        }
        return ans;
    }
};