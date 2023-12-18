//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code herebitset<32> binary(number);
        bitset<32> a(m), b(n);
        string s = a.to_string(), t = b.to_string();
        for(int i = 31; i>=0; i--) 
            if(s[i] != t[i])
                return 32 - i;
        return -1;
    }
};