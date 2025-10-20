class Solution:
    def __init__(self):
        self.v = [0] * 26
        self.ans = 0
    
    def f(self, v, s, n):
        length = 0
        for i in range(26):
            if self.v[i] > 1:
                return
            if self.v[i] != 0:
                length += 1
        self.ans = max(self.ans, length)
        for i in range(s, n):
            for ch in v[i]:
                self.v[ord(ch) - ord('a')] += 1
            self.f(v, i + 1, n)
            for ch in v[i]:
                self.v[ord(ch) - ord('a')] -= 1
    
    def maxLength(self, arr):
        self.f(arr, 0, len(arr))
        return self.ans
