class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        a, ans = sorted(happiness, reverse = True), 0
        for i in range(k):
            ans += max(0,a[i] - i)
        return ans