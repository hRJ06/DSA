class Solution:
    def largestOddNumber(self, num: str) -> str:
        n = len(num)
        index = -1
        for i in range(n):
            if int(num[i]) & 1:
                index = i
        return num[:index + 1]
