class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0;
        for(auto &i : nums) {
            odd += (i & 1);
            even += !(i & 1);
        }
        bool oddEven = true, evenOdd = true;
        int oE = 0, eO = 0;
        for(auto &i : nums) {
            if(oddEven and (i & 1)) {
                oE++;
                oddEven = !oddEven;
            }
            if(!oddEven and !(i & 1)) {
                oE++;
                oddEven = !oddEven;
            }
        }
        for(auto &i : nums) {
            if(evenOdd and !(i & 1)) {
                eO++;
                evenOdd = !evenOdd;
            }
            if(!evenOdd and (i & 1)) {
                eO++;
                evenOdd = !evenOdd;
            }
        }
        return max({even, odd, oE, eO});
    }
};