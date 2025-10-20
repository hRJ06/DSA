class Solution:
    def totalMoney(self, n: int) -> int:
        ans = 0
        count = 0
        track = 1
        for i in range(1,n + 1):
            count += 1
            ans += count
            if i % 7 == 0:
                count = track
                track += 1
        return ans
