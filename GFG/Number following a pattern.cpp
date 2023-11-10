class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.length(), place = 1;
        string ans(n + 1,' ');
        for(int i = 0; i<=n; i++) {
            if(i == n or S[i] == 'I') {
                for(int j = i - 1; j>=-1; j--) {
                    ans[j + 1] = place + '0';
                    place++;
                    if(j >= 0 and S[j] == 'I') break;
                }
            }
        }
        return ans;
    }
};
