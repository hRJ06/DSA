class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        int num = 0, den = 1, i = 0;
        while(i < n) {
            int cur_num = 0, cur_den = 0;
            bool isNeg = expression[i] == '-';
            if(expression[i] == '+' or expression[i] == '-') i++;
            while(i < n and isdigit(expression[i])) 
                cur_num = (cur_num * 10) + (expression[i++] - '0');
            if(isNeg) cur_num *= -1;
            i++;
            while(i < n and isdigit(expression[i])) 
                cur_den = (cur_den * 10) + (expression[i++] - '0');
            num = (num * cur_den) + (cur_num * den);
            den *= cur_den;
        }
        int gcd = abs(__gcd(num, den));
        num /= gcd;
        den /= gcd;
        return to_string(num) + "/" + to_string(den);
    }
};