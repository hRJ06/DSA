from typing import List
class Solution:
    def f(self, day, total, N, coins,dp):
        if total != 0 and (total % 24 == 0 or total % 20 == 0 or total == 2024):
            return True
        if day >= N:
            return False
        if dp[day][total] != -1:
            return dp[day][total]
        a = self.f(day + 1, total + coins[day], N, coins,dp)
        b = self.f(day + 1, total, N, coins,dp)
        dp[day][total] = a or b
        return dp[day][total]

    def isPossible(self, N: int, coins: List[int]) -> bool:
        total = 0
        for i in coins:
            total += i
        dp = [[-1 for j in range(total + 1)] for i in range(N)]
        return self.f(0, 0, N, coins,dp)
        