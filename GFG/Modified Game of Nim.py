class Solution:
    def findWinner(self, n, A):
        # code here
        xor = 0
        for i in range(n):
            xor ^= A[i]
        if not xor or not (n & 1):
            return 1
        else:
            return 2
        