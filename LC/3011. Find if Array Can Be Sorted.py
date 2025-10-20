class Solution:
    def f(self, n):
        c = 0
        while n > 0:
            c += n & 1
            n >>= 1
        return c
    def canSortArray(self, nums):
        for i in range(1, len(nums)):
            if nums[i - 1] > nums[i]:
                if self.f(nums[i - 1]) != self.f(nums[i]):
                    return False
                nums[i - 1], nums[i] = nums[i], nums[i - 1]
                j = i - 1
                while j > 0 and nums[j] < nums[j - 1]:
                    if self.f(nums[j]) != self.f(nums[j - 1]):
                        return False
                    nums[j], nums[j - 1] = nums[j - 1], nums[j]
                    j -= 1
        return True
