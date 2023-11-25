class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles = sorted(piles)
        n = len(piles)
        ans = 0
        for i in range(n // 3,n,2):
            ans += piles[i]
        return ans

        