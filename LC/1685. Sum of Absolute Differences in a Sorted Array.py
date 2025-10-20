class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        total = 0
        left = 0
        for val in nums:
            total += val
        for i in range(n):
            a = (nums[i] * i - left)
            b = (total - left - nums[i] * (n - i))
            ans.append(a + b)
            left += nums[i]
        return ans

        