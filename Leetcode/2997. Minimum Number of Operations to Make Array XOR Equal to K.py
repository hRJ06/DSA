class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        count = 0
        n = len(nums)
        for i in range(n):
            count ^= nums[i]
        store = count ^ k
        if store != 0:
            ans = 0
            while store > 0:
                ans += store & 1
                store >>= 1
            return ans
        else:
            return 0
