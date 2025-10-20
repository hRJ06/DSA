class Solution:
    def rev(self, n):
        ans = 0
        while n > 0:
            ans = (ans * 10) + (n % 10)
            n //= 10
        return ans
    def countNicePairs(self, nums: List[int]) -> int:
        Map = {}
        n = len(nums)
        MOD = int(1e9) + 7
        ans = 0
        for i in range(n):
            a = nums[i] - self.rev(nums[i])
            Map[a] = Map.get(a, 0) + 1
        for key, value in Map.items():
            ans = (ans + (value * (value - 1) // 2)) % MOD
        return ans
