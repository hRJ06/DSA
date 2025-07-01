class Solution:
    def possibleStringCount(self, s: str) -> int:
        n = len(s)
        res = 1 
        i = j = 0
        while j < n:
            cnt = 0
            while j < n and s[j] == s[i]:
                cnt += 1
                j += 1
            i = j
            res += cnt - 1 
        return res
