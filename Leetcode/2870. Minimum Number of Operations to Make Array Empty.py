class Solution:
    def minOperations(self, nums: List[int]) -> int:
        Map = {}
        n = len(nums)
        for i in range(n):
            Map[nums[i]] = Map.get(nums[i],0) + 1
        ans = 0
        for key,value in Map.items():
            if value == 1:
                return -1
            else:
                ans += (value // 3)
                if value % 3 != 0:
                    ans += 1
        return ans