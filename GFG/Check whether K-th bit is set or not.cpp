class Solution:
    
    #Function to check if Kth bit is set or not.
    def checkKthBit(self, n,k):
        #Your code here
        count = 0;
        while n > 0:
            bit = n & 1
            if count == k:
                return bit == 1;
            count += 1
            n >>= 1