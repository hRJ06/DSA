class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        bitset<32> binary(x);
        bitset<32> reverse;
        for(int i = 0; i<32; i++)
            reverse[i] = binary[31 - i];
        return reverse.to_ulong();
            
    }
};