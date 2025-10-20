class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length();
        int ans = n;
        for(int i = n - 1; i>=0; i--) {
            for(int j = i - 1; j>=0; j--) {
                int no = (num[i] - '0') + (num[j] - '0') * 10;
                if(no % 25 == 0) ans = min(ans,n - j - 2);
            }
            if(num[i] == '0') ans = min(ans, n - 1);
        }
        return ans;
    }
};