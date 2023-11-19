class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums = sorted(nums,reverse=True)
        count = 1
        ans = 0
        n = len(nums)
        for i in range (1,n):
            if nums[i] != nums[i - 1]:
                ans += count
            count += 1
        return ans
        