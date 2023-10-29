# Approach 1
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1,n):
                if(nums[i] + nums[j] == target):
                    return [i,j]
        

# Approach 2
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        Map = {}
        for i,j in enumerate(nums):
            k = target - j
            if k in Map:
                return [Map[k],i]
            else:
                Map[j] = i
