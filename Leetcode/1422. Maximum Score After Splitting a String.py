class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        score = 0
        zero = 0
        one = 0
        for i in range(n):
            if s[i] == '1':
                one += 1
        for i in range(n - 1):
            if s[i] == '0':
                zero += 1
            else:
                zero -= 1
            score = max(score,zero + one)
        return score
            
        
    