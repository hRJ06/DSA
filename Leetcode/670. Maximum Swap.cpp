class Solution {
public:
    int maximumSwap(int num) {
        vector<int> last(10, -1);
        string n = to_string(num);
        for(int i = 0; i<n.length(); i++) 
            last[n[i] - '0'] = i;
        for(int i = 0; i<n.length(); i++) {
            for(int digit = 9; digit > n[i] - '0'; digit--) {
                if(last[digit] != -1 and last[digit] > i) {
                    swap(n[last[digit]], n[i]);
                    return stoi(n);
                }
            }
        }
        return num;
    }
};