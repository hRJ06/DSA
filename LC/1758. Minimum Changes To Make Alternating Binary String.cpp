class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int a = 0, b = 0;
        for(int i = 0; i<n; i++) {
            if(!(i % 2)) {
                if(s[i] != '0') {
                    b++;
                }
                else {
                    a++;
                }
            }
            else {
                if(s[i] != '0') {
                    a++;
                }
                else {
                    b++;
                }
            }
        }   
        return min(a,b);
    }
};