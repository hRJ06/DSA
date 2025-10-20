class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        M1, M2, check, ans = {}, {}, 0, ""
        for i in range(len(s)):
            M1[s[i]] = M1.get(s[i], 0) + 1
            check = max(check, M1[s[i]])
            M2[s[i]] = i
        for i in range(len(s)):
            if M1[s[i]] == check and M2[s[i]] == i:
                ans += s[i]     
        return ans
