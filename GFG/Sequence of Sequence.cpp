class Solution{
private:
    int f(int cur_no,int m,int n) {
        if(!n) return 1;
        int ans = 0;
        for(int i = 2 * cur_no; i<=m; i++) {
            ans += f(i,m,n - 1);
        }
        return ans;
    }
public:
    int numberSequence(int m, int n){
        // code here
        int ans = 0;
        for(int i = 1; i<=m; i++) {
            ans += f(i,m,n - 1);
        }
        return ans;
    }
};