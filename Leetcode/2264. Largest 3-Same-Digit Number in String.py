class Solution:
    def largestGoodInteger(self, num: str) -> str:
        char = '\0'
        n = len(num)
        for i in range(n - 2):
            if num[i] == num[i + 1] and num[i + 1] == num[i + 2]:
                char = max(char,num[i])
        return "" if char is '\0' else char * 3