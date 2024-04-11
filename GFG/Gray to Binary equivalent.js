class Solution {
    // function to convert a given Gray equivalent n to Binary equivalent.
    grayToBinary(n)
    {
        // code here
        var binary = 0;
        while(n > 0) {
            binary ^= n;
            n >>= 1;
        }
        return binary;
    }
}