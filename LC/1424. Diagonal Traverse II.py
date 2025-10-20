class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        Map = {}
        n = len(nums)
        for i in range(n):
            for j in range(len(nums[i])):
                if i + j not in Map:
                    Map[i + j] = []
                Map[i + j].append(nums[i][j])
        
        ans = []
        for key, value in Map.items():
            ans.extend(reversed(value))
        return ans


        