class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        Set = set(['a','e','i','o','u','A','E','I','O','U'])
        n = len(s)
        total = 0
        for i in range(n):
            if s[i] in Set:
                if i < n // 2:
                    total += 1
                else:
                    total -= 1
        return True if not total else False