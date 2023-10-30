#User function Template for python3

class Solution:
    def sumXOR(self, arr, n): 
        ans = 0
        for i in range(32):
            one = 0
            zero = 0
            for j in range(n):
                if arr[j] & 1:
                    one += 1
                else:
                    zero += 1
                arr[j] >>= 1
            ans += (one * zero) * (1 << i)
        return ans
