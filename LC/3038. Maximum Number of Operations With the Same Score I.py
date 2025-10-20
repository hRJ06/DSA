class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        ans, i, n = 1, 2, len(nums) - 1
        while i < n:
            if nums[i] + nums[i + 1] != nums[0] + nums[1]:
                break
            else:
                ans += 1
                i += 2
        return ans