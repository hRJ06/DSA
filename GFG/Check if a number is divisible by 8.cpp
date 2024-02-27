class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n = s.size();
        if(n <= 3) {
            int store = stoi(s);
            if(!(store % 8)) return 1;
            else return -1;
        }
        else {
            int store = stoi(s.substr(n - 3, 3));
            if(!(store % 8)) return 1;
            else return -1;
        }
        
    }
};