class Solution {
    public int minimizeXor(int num1, int num2) {
        int count = Integer.bitCount(num2);
        int result = 0;
        /* 
            The idea is in order to minimize the xor value I will try to make MSB which are 1 in num1 to 1 in result as well.
            In case if no of 1 in num1 less than no of 1 in num2 make the LSB of result to 1 which are 0 in num1.
        */
        for(int i = 31; i>=0; i--) {
            if((num1 & (1 << i)) != 0 && count > 0) {
                result |= (1 << i); 
                count--;
            }
        }
        for(int i = 0; i<=31 && count>0; i++) {
            if((result & (1 << i)) == 0) {
                result |= (1 << i);
                count--;
            }
        }
        return result;
    }
}
