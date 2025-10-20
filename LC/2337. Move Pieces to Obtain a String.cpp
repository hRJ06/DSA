class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.length();
        while(i <= n and j <= n) {
            while(i < n and start[i] == '_') i++;
            while(j < n and target[j] == '_') j++;
            if(i == n and j == n) return true;
            if(i == n or j == n) return false;
            if(start[i] != target[j]) return false;
            if(start[i] == 'L') {
                if(i < j) return false;
            }   
            else {
                if(i > j) return false;
            }
            i++;
            j++;

        }
        return true;
    }
};