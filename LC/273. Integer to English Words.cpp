class Solution {
private:
    vector<string> belowTen = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string solve(int n) {
        if(n < 10) 
            return belowTen[n];
        if(n < 20) 
            return belowTwenty[n - 10];
        if(n < 100) { 
            string tens = "";
            switch (n / 10) {
                case 2: tens = "Twenty"; break;
                case 3: tens = "Thirty"; break;
                case 4: tens = "Forty"; break;
                case 5: tens = "Fifty"; break;
                case 6: tens = "Sixty"; break;
                case 7: tens = "Seventy"; break;
                case 8: tens = "Eighty"; break;
                case 9: tens = "Ninety"; break;
            }
            return tens + ((n % 10 != 0) ? " " + belowTen[n % 10] : "");
        }
        if(n < 1000)
            return solve(n / 100) + " Hundred" + ((n % 100 != 0) ? " " + solve(n % 100) : "");
        if(n < 1000000)
            return solve(n / 1000) + " Thousand" + ((n % 1000 != 0) ? " " + solve(n % 1000) : "");
        if(n < 1000000000) 
            return solve(n / 1000000) + " Million" + ((n % 1000000 != 0) ? " " + solve(n % 1000000) : "");
        return solve(n / 1000000000) + " Billion" + ((n % 1000000000 != 0) ? " " + solve(n % 1000000000) : "");
    }
public:
    string numberToWords(int n) {
        if(!n) return "Zero";
        return solve(n);
    }
};
