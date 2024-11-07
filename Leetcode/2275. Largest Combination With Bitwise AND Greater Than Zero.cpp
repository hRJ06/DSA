class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        /* If a combination needs to have AND greater than 0, then for all those numbers in the combination, atleast one bit should be 1 for all the numbers */
        vector<int> bits(32, 0);
        for(auto &i : candidates) {
            for(int j = 0; j<32; j++) {
                bits[j] += (i >> j) & 1;
            }
        }
        return *max_element(bits.begin(), bits.end());
    }
};