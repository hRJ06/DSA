class Solution:

    def countStr(self, n):
        # code here
        return 1 + n + n + n * (n - 1) + n * (n - 1) // 2 + n * (n - 1) * (n - 2) // 2
