class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = count(s.begin(),s.end(),'1');
        int n = s.length();
        string ans(n,'0');
        if(one > 1) {
            one--;
            int i = 0;
            while(one--) 
                ans[i++] = '1';
            ans[n - 1] = '1';
        }
        else 
            ans[n - 1] =  '1';
        return ans;
    }
};